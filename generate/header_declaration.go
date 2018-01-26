package generate

import (
	"strings"
)

type HeaderDeclaration interface {
	Declaration() string
	Id() string
	Dependencies() []string
	ParentId() string
	AddChild(HeaderDeclaration)
}

type staticDeclaration struct {
	declaration  string
	dependencies []string
	id           string
	parentId     string
}

func (d *staticDeclaration) Declaration() string {
	return d.declaration
}

func (d *staticDeclaration) Dependencies() []string {
	return d.dependencies
}

func (d *staticDeclaration) Id() string {
	return d.id
}

func (d *staticDeclaration) ParentId() string {
	return d.parentId
}

func (d *staticDeclaration) AddChild(HeaderDeclaration) {
	panic("static declaration cannot have children")
}

func StaticDeclaration(id, decl string, deps []string, parentId string) HeaderDeclaration {
	return &staticDeclaration{
		declaration:  decl,
		dependencies: deps,
		id:           id,
		parentId:     parentId,
	}
}

type StructDeclaration struct {
	Name                     string
	FieldDeclarations        []string
	Base                     string
	FieldAndBaseDependencies []string
	MemberDeclarations       []HeaderDeclaration
}

func (d *StructDeclaration) Declaration() string {
	ret := "struct " + d.Name
	if d.Base != "" {
		ret += " : " + d.Base
	}
	ret += " {\n"
	for _, fd := range d.FieldDeclarations {
		ret += fd
	}
	for _, md := range d.MemberDeclarations {
		ret += md.Declaration()
	}
	if d.Base != "" && !strings.HasPrefix(d.Base, "::gostd::Array") {
		ret += "template <typename... Args> explicit " + d.Name + "(Args&&... args) : " + d.Base + "(cpp::forward<Args>(args)...) {}"
	}
	ret += "};\n"
	return ret
}

func (d *StructDeclaration) Dependencies() []string {
	return d.FieldAndBaseDependencies
}

func (d *StructDeclaration) Id() string {
	return d.Name
}

func (d *StructDeclaration) ParentId() string {
	return ""
}

func (d *StructDeclaration) AddChild(decl HeaderDeclaration) {
	d.MemberDeclarations = append(d.MemberDeclarations, decl)
}

func SortHeaderDeclarations(decls []HeaderDeclaration) (result []HeaderDeclaration) {
	m := make(map[string]HeaderDeclaration)
	for _, decl := range decls {
		if decl.ParentId() == "" {
			m[decl.Id()] = decl
		}
	}
	for _, decl := range decls {
		if p := decl.ParentId(); p != "" {
			m[p].AddChild(decl)
		}
	}

	sorted := make(map[string]bool)
	for len(m) > 0 {
		didAdd := false
		for id, decl := range m {
			canAdd := true
			for _, dep := range decl.Dependencies() {
				if _, ok := sorted[dep]; !ok {
					canAdd = false
					break
				}
			}
			if canAdd {
				result = append(result, decl)
				sorted[id] = true
				delete(m, id)
				didAdd = true
				break
			}
		}
		if !didAdd {
			panic("unable to resolve declaration order")
		}
	}

	return
}