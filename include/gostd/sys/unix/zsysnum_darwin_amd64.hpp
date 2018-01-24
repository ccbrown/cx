#pragma once

#include <gostd.hpp>

namespace gostd::sys::unix {

constexpr auto SYS_SYSCALL                        = UntypedConstant(0);
constexpr auto SYS_EXIT                           = UntypedConstant(1);
constexpr auto SYS_FORK                           = UntypedConstant(2);
constexpr auto SYS_READ                           = UntypedConstant(3);
constexpr auto SYS_WRITE                          = UntypedConstant(4);
constexpr auto SYS_OPEN                           = UntypedConstant(5);
constexpr auto SYS_CLOSE                          = UntypedConstant(6);
constexpr auto SYS_WAIT4                          = UntypedConstant(7);
constexpr auto SYS_LINK                           = UntypedConstant(9);
constexpr auto SYS_UNLINK                         = UntypedConstant(10);
constexpr auto SYS_CHDIR                          = UntypedConstant(12);
constexpr auto SYS_FCHDIR                         = UntypedConstant(13);
constexpr auto SYS_MKNOD                          = UntypedConstant(14);
constexpr auto SYS_CHMOD                          = UntypedConstant(15);
constexpr auto SYS_CHOWN                          = UntypedConstant(16);
constexpr auto SYS_GETFSSTAT                      = UntypedConstant(18);
constexpr auto SYS_GETPID                         = UntypedConstant(20);
constexpr auto SYS_SETUID                         = UntypedConstant(23);
constexpr auto SYS_GETUID                         = UntypedConstant(24);
constexpr auto SYS_GETEUID                        = UntypedConstant(25);
constexpr auto SYS_PTRACE                         = UntypedConstant(26);
constexpr auto SYS_RECVMSG                        = UntypedConstant(27);
constexpr auto SYS_SENDMSG                        = UntypedConstant(28);
constexpr auto SYS_RECVFROM                       = UntypedConstant(29);
constexpr auto SYS_ACCEPT                         = UntypedConstant(30);
constexpr auto SYS_GETPEERNAME                    = UntypedConstant(31);
constexpr auto SYS_GETSOCKNAME                    = UntypedConstant(32);
constexpr auto SYS_ACCESS                         = UntypedConstant(33);
constexpr auto SYS_CHFLAGS                        = UntypedConstant(34);
constexpr auto SYS_FCHFLAGS                       = UntypedConstant(35);
constexpr auto SYS_SYNC                           = UntypedConstant(36);
constexpr auto SYS_KILL                           = UntypedConstant(37);
constexpr auto SYS_GETPPID                        = UntypedConstant(39);
constexpr auto SYS_DUP                            = UntypedConstant(41);
constexpr auto SYS_PIPE                           = UntypedConstant(42);
constexpr auto SYS_GETEGID                        = UntypedConstant(43);
constexpr auto SYS_SIGACTION                      = UntypedConstant(46);
constexpr auto SYS_GETGID                         = UntypedConstant(47);
constexpr auto SYS_SIGPROCMASK                    = UntypedConstant(48);
constexpr auto SYS_GETLOGIN                       = UntypedConstant(49);
constexpr auto SYS_SETLOGIN                       = UntypedConstant(50);
constexpr auto SYS_ACCT                           = UntypedConstant(51);
constexpr auto SYS_SIGPENDING                     = UntypedConstant(52);
constexpr auto SYS_SIGALTSTACK                    = UntypedConstant(53);
constexpr auto SYS_IOCTL                          = UntypedConstant(54);
constexpr auto SYS_REBOOT                         = UntypedConstant(55);
constexpr auto SYS_REVOKE                         = UntypedConstant(56);
constexpr auto SYS_SYMLINK                        = UntypedConstant(57);
constexpr auto SYS_READLINK                       = UntypedConstant(58);
constexpr auto SYS_EXECVE                         = UntypedConstant(59);
constexpr auto SYS_UMASK                          = UntypedConstant(60);
constexpr auto SYS_CHROOT                         = UntypedConstant(61);
constexpr auto SYS_MSYNC                          = UntypedConstant(65);
constexpr auto SYS_VFORK                          = UntypedConstant(66);
constexpr auto SYS_MUNMAP                         = UntypedConstant(73);
constexpr auto SYS_MPROTECT                       = UntypedConstant(74);
constexpr auto SYS_MADVISE                        = UntypedConstant(75);
constexpr auto SYS_MINCORE                        = UntypedConstant(78);
constexpr auto SYS_GETGROUPS                      = UntypedConstant(79);
constexpr auto SYS_SETGROUPS                      = UntypedConstant(80);
constexpr auto SYS_GETPGRP                        = UntypedConstant(81);
constexpr auto SYS_SETPGID                        = UntypedConstant(82);
constexpr auto SYS_SETITIMER                      = UntypedConstant(83);
constexpr auto SYS_SWAPON                         = UntypedConstant(85);
constexpr auto SYS_GETITIMER                      = UntypedConstant(86);
constexpr auto SYS_GETDTABLESIZE                  = UntypedConstant(89);
constexpr auto SYS_DUP2                           = UntypedConstant(90);
constexpr auto SYS_FCNTL                          = UntypedConstant(92);
constexpr auto SYS_SELECT                         = UntypedConstant(93);
constexpr auto SYS_FSYNC                          = UntypedConstant(95);
constexpr auto SYS_SETPRIORITY                    = UntypedConstant(96);
constexpr auto SYS_SOCKET                         = UntypedConstant(97);
constexpr auto SYS_CONNECT                        = UntypedConstant(98);
constexpr auto SYS_GETPRIORITY                    = UntypedConstant(100);
constexpr auto SYS_BIND                           = UntypedConstant(104);
constexpr auto SYS_SETSOCKOPT                     = UntypedConstant(105);
constexpr auto SYS_LISTEN                         = UntypedConstant(106);
constexpr auto SYS_SIGSUSPEND                     = UntypedConstant(111);
constexpr auto SYS_GETTIMEOFDAY                   = UntypedConstant(116);
constexpr auto SYS_GETRUSAGE                      = UntypedConstant(117);
constexpr auto SYS_GETSOCKOPT                     = UntypedConstant(118);
constexpr auto SYS_READV                          = UntypedConstant(120);
constexpr auto SYS_WRITEV                         = UntypedConstant(121);
constexpr auto SYS_SETTIMEOFDAY                   = UntypedConstant(122);
constexpr auto SYS_FCHOWN                         = UntypedConstant(123);
constexpr auto SYS_FCHMOD                         = UntypedConstant(124);
constexpr auto SYS_SETREUID                       = UntypedConstant(126);
constexpr auto SYS_SETREGID                       = UntypedConstant(127);
constexpr auto SYS_RENAME                         = UntypedConstant(128);
constexpr auto SYS_FLOCK                          = UntypedConstant(131);
constexpr auto SYS_MKFIFO                         = UntypedConstant(132);
constexpr auto SYS_SENDTO                         = UntypedConstant(133);
constexpr auto SYS_SHUTDOWN                       = UntypedConstant(134);
constexpr auto SYS_SOCKETPAIR                     = UntypedConstant(135);
constexpr auto SYS_MKDIR                          = UntypedConstant(136);
constexpr auto SYS_RMDIR                          = UntypedConstant(137);
constexpr auto SYS_UTIMES                         = UntypedConstant(138);
constexpr auto SYS_FUTIMES                        = UntypedConstant(139);
constexpr auto SYS_ADJTIME                        = UntypedConstant(140);
constexpr auto SYS_GETHOSTUUID                    = UntypedConstant(142);
constexpr auto SYS_SETSID                         = UntypedConstant(147);
constexpr auto SYS_GETPGID                        = UntypedConstant(151);
constexpr auto SYS_SETPRIVEXEC                    = UntypedConstant(152);
constexpr auto SYS_PREAD                          = UntypedConstant(153);
constexpr auto SYS_PWRITE                         = UntypedConstant(154);
constexpr auto SYS_NFSSVC                         = UntypedConstant(155);
constexpr auto SYS_STATFS                         = UntypedConstant(157);
constexpr auto SYS_FSTATFS                        = UntypedConstant(158);
constexpr auto SYS_UNMOUNT                        = UntypedConstant(159);
constexpr auto SYS_GETFH                          = UntypedConstant(161);
constexpr auto SYS_QUOTACTL                       = UntypedConstant(165);
constexpr auto SYS_MOUNT                          = UntypedConstant(167);
constexpr auto SYS_CSOPS                          = UntypedConstant(169);
constexpr auto SYS_CSOPS_AUDITTOKEN               = UntypedConstant(170);
constexpr auto SYS_WAITID                         = UntypedConstant(173);
constexpr auto SYS_KDEBUG_TYPEFILTER              = UntypedConstant(177);
constexpr auto SYS_KDEBUG_TRACE_STRING            = UntypedConstant(178);
constexpr auto SYS_KDEBUG_TRACE64                 = UntypedConstant(179);
constexpr auto SYS_KDEBUG_TRACE                   = UntypedConstant(180);
constexpr auto SYS_SETGID                         = UntypedConstant(181);
constexpr auto SYS_SETEGID                        = UntypedConstant(182);
constexpr auto SYS_SETEUID                        = UntypedConstant(183);
constexpr auto SYS_SIGRETURN                      = UntypedConstant(184);
constexpr auto SYS_THREAD_SELFCOUNTS              = UntypedConstant(186);
constexpr auto SYS_FDATASYNC                      = UntypedConstant(187);
constexpr auto SYS_STAT                           = UntypedConstant(188);
constexpr auto SYS_FSTAT                          = UntypedConstant(189);
constexpr auto SYS_LSTAT                          = UntypedConstant(190);
constexpr auto SYS_PATHCONF                       = UntypedConstant(191);
constexpr auto SYS_FPATHCONF                      = UntypedConstant(192);
constexpr auto SYS_GETRLIMIT                      = UntypedConstant(194);
constexpr auto SYS_SETRLIMIT                      = UntypedConstant(195);
constexpr auto SYS_GETDIRENTRIES                  = UntypedConstant(196);
constexpr auto SYS_MMAP                           = UntypedConstant(197);
constexpr auto SYS_LSEEK                          = UntypedConstant(199);
constexpr auto SYS_TRUNCATE                       = UntypedConstant(200);
constexpr auto SYS_FTRUNCATE                      = UntypedConstant(201);
constexpr auto SYS_SYSCTL                         = UntypedConstant(202);
constexpr auto SYS_MLOCK                          = UntypedConstant(203);
constexpr auto SYS_MUNLOCK                        = UntypedConstant(204);
constexpr auto SYS_UNDELETE                       = UntypedConstant(205);
constexpr auto SYS_OPEN_DPROTECTED_NP             = UntypedConstant(216);
constexpr auto SYS_GETATTRLIST                    = UntypedConstant(220);
constexpr auto SYS_SETATTRLIST                    = UntypedConstant(221);
constexpr auto SYS_GETDIRENTRIESATTR              = UntypedConstant(222);
constexpr auto SYS_EXCHANGEDATA                   = UntypedConstant(223);
constexpr auto SYS_SEARCHFS                       = UntypedConstant(225);
constexpr auto SYS_DELETE                         = UntypedConstant(226);
constexpr auto SYS_COPYFILE                       = UntypedConstant(227);
constexpr auto SYS_FGETATTRLIST                   = UntypedConstant(228);
constexpr auto SYS_FSETATTRLIST                   = UntypedConstant(229);
constexpr auto SYS_POLL                           = UntypedConstant(230);
constexpr auto SYS_WATCHEVENT                     = UntypedConstant(231);
constexpr auto SYS_WAITEVENT                      = UntypedConstant(232);
constexpr auto SYS_MODWATCH                       = UntypedConstant(233);
constexpr auto SYS_GETXATTR                       = UntypedConstant(234);
constexpr auto SYS_FGETXATTR                      = UntypedConstant(235);
constexpr auto SYS_SETXATTR                       = UntypedConstant(236);
constexpr auto SYS_FSETXATTR                      = UntypedConstant(237);
constexpr auto SYS_REMOVEXATTR                    = UntypedConstant(238);
constexpr auto SYS_FREMOVEXATTR                   = UntypedConstant(239);
constexpr auto SYS_LISTXATTR                      = UntypedConstant(240);
constexpr auto SYS_FLISTXATTR                     = UntypedConstant(241);
constexpr auto SYS_FSCTL                          = UntypedConstant(242);
constexpr auto SYS_INITGROUPS                     = UntypedConstant(243);
constexpr auto SYS_POSIX_SPAWN                    = UntypedConstant(244);
constexpr auto SYS_FFSCTL                         = UntypedConstant(245);
constexpr auto SYS_NFSCLNT                        = UntypedConstant(247);
constexpr auto SYS_FHOPEN                         = UntypedConstant(248);
constexpr auto SYS_MINHERIT                       = UntypedConstant(250);
constexpr auto SYS_SEMSYS                         = UntypedConstant(251);
constexpr auto SYS_MSGSYS                         = UntypedConstant(252);
constexpr auto SYS_SHMSYS                         = UntypedConstant(253);
constexpr auto SYS_SEMCTL                         = UntypedConstant(254);
constexpr auto SYS_SEMGET                         = UntypedConstant(255);
constexpr auto SYS_SEMOP                          = UntypedConstant(256);
constexpr auto SYS_MSGCTL                         = UntypedConstant(258);
constexpr auto SYS_MSGGET                         = UntypedConstant(259);
constexpr auto SYS_MSGSND                         = UntypedConstant(260);
constexpr auto SYS_MSGRCV                         = UntypedConstant(261);
constexpr auto SYS_SHMAT                          = UntypedConstant(262);
constexpr auto SYS_SHMCTL                         = UntypedConstant(263);
constexpr auto SYS_SHMDT                          = UntypedConstant(264);
constexpr auto SYS_SHMGET                         = UntypedConstant(265);
constexpr auto SYS_SHM_OPEN                       = UntypedConstant(266);
constexpr auto SYS_SHM_UNLINK                     = UntypedConstant(267);
constexpr auto SYS_SEM_OPEN                       = UntypedConstant(268);
constexpr auto SYS_SEM_CLOSE                      = UntypedConstant(269);
constexpr auto SYS_SEM_UNLINK                     = UntypedConstant(270);
constexpr auto SYS_SEM_WAIT                       = UntypedConstant(271);
constexpr auto SYS_SEM_TRYWAIT                    = UntypedConstant(272);
constexpr auto SYS_SEM_POST                       = UntypedConstant(273);
constexpr auto SYS_SYSCTLBYNAME                   = UntypedConstant(274);
constexpr auto SYS_OPEN_EXTENDED                  = UntypedConstant(277);
constexpr auto SYS_UMASK_EXTENDED                 = UntypedConstant(278);
constexpr auto SYS_STAT_EXTENDED                  = UntypedConstant(279);
constexpr auto SYS_LSTAT_EXTENDED                 = UntypedConstant(280);
constexpr auto SYS_FSTAT_EXTENDED                 = UntypedConstant(281);
constexpr auto SYS_CHMOD_EXTENDED                 = UntypedConstant(282);
constexpr auto SYS_FCHMOD_EXTENDED                = UntypedConstant(283);
constexpr auto SYS_ACCESS_EXTENDED                = UntypedConstant(284);
constexpr auto SYS_SETTID                         = UntypedConstant(285);
constexpr auto SYS_GETTID                         = UntypedConstant(286);
constexpr auto SYS_SETSGROUPS                     = UntypedConstant(287);
constexpr auto SYS_GETSGROUPS                     = UntypedConstant(288);
constexpr auto SYS_SETWGROUPS                     = UntypedConstant(289);
constexpr auto SYS_GETWGROUPS                     = UntypedConstant(290);
constexpr auto SYS_MKFIFO_EXTENDED                = UntypedConstant(291);
constexpr auto SYS_MKDIR_EXTENDED                 = UntypedConstant(292);
constexpr auto SYS_IDENTITYSVC                    = UntypedConstant(293);
constexpr auto SYS_SHARED_REGION_CHECK_NP         = UntypedConstant(294);
constexpr auto SYS_VM_PRESSURE_MONITOR            = UntypedConstant(296);
constexpr auto SYS_PSYNCH_RW_LONGRDLOCK           = UntypedConstant(297);
constexpr auto SYS_PSYNCH_RW_YIELDWRLOCK          = UntypedConstant(298);
constexpr auto SYS_PSYNCH_RW_DOWNGRADE            = UntypedConstant(299);
constexpr auto SYS_PSYNCH_RW_UPGRADE              = UntypedConstant(300);
constexpr auto SYS_PSYNCH_MUTEXWAIT               = UntypedConstant(301);
constexpr auto SYS_PSYNCH_MUTEXDROP               = UntypedConstant(302);
constexpr auto SYS_PSYNCH_CVBROAD                 = UntypedConstant(303);
constexpr auto SYS_PSYNCH_CVSIGNAL                = UntypedConstant(304);
constexpr auto SYS_PSYNCH_CVWAIT                  = UntypedConstant(305);
constexpr auto SYS_PSYNCH_RW_RDLOCK               = UntypedConstant(306);
constexpr auto SYS_PSYNCH_RW_WRLOCK               = UntypedConstant(307);
constexpr auto SYS_PSYNCH_RW_UNLOCK               = UntypedConstant(308);
constexpr auto SYS_PSYNCH_RW_UNLOCK2              = UntypedConstant(309);
constexpr auto SYS_GETSID                         = UntypedConstant(310);
constexpr auto SYS_SETTID_WITH_PID                = UntypedConstant(311);
constexpr auto SYS_PSYNCH_CVCLRPREPOST            = UntypedConstant(312);
constexpr auto SYS_AIO_FSYNC                      = UntypedConstant(313);
constexpr auto SYS_AIO_RETURN                     = UntypedConstant(314);
constexpr auto SYS_AIO_SUSPEND                    = UntypedConstant(315);
constexpr auto SYS_AIO_CANCEL                     = UntypedConstant(316);
constexpr auto SYS_AIO_ERROR                      = UntypedConstant(317);
constexpr auto SYS_AIO_READ                       = UntypedConstant(318);
constexpr auto SYS_AIO_WRITE                      = UntypedConstant(319);
constexpr auto SYS_LIO_LISTIO                     = UntypedConstant(320);
constexpr auto SYS_IOPOLICYSYS                    = UntypedConstant(322);
constexpr auto SYS_PROCESS_POLICY                 = UntypedConstant(323);
constexpr auto SYS_MLOCKALL                       = UntypedConstant(324);
constexpr auto SYS_MUNLOCKALL                     = UntypedConstant(325);
constexpr auto SYS_ISSETUGID                      = UntypedConstant(327);
constexpr auto SYS___PTHREAD_KILL                 = UntypedConstant(328);
constexpr auto SYS___PTHREAD_SIGMASK              = UntypedConstant(329);
constexpr auto SYS___SIGWAIT                      = UntypedConstant(330);
constexpr auto SYS___DISABLE_THREADSIGNAL         = UntypedConstant(331);
constexpr auto SYS___PTHREAD_MARKCANCEL           = UntypedConstant(332);
constexpr auto SYS___PTHREAD_CANCELED             = UntypedConstant(333);
constexpr auto SYS___SEMWAIT_SIGNAL               = UntypedConstant(334);
constexpr auto SYS_PROC_INFO                      = UntypedConstant(336);
constexpr auto SYS_SENDFILE                       = UntypedConstant(337);
constexpr auto SYS_STAT64                         = UntypedConstant(338);
constexpr auto SYS_FSTAT64                        = UntypedConstant(339);
constexpr auto SYS_LSTAT64                        = UntypedConstant(340);
constexpr auto SYS_STAT64_EXTENDED                = UntypedConstant(341);
constexpr auto SYS_LSTAT64_EXTENDED               = UntypedConstant(342);
constexpr auto SYS_FSTAT64_EXTENDED               = UntypedConstant(343);
constexpr auto SYS_GETDIRENTRIES64                = UntypedConstant(344);
constexpr auto SYS_STATFS64                       = UntypedConstant(345);
constexpr auto SYS_FSTATFS64                      = UntypedConstant(346);
constexpr auto SYS_GETFSSTAT64                    = UntypedConstant(347);
constexpr auto SYS___PTHREAD_CHDIR                = UntypedConstant(348);
constexpr auto SYS___PTHREAD_FCHDIR               = UntypedConstant(349);
constexpr auto SYS_AUDIT                          = UntypedConstant(350);
constexpr auto SYS_AUDITON                        = UntypedConstant(351);
constexpr auto SYS_GETAUID                        = UntypedConstant(353);
constexpr auto SYS_SETAUID                        = UntypedConstant(354);
constexpr auto SYS_GETAUDIT_ADDR                  = UntypedConstant(357);
constexpr auto SYS_SETAUDIT_ADDR                  = UntypedConstant(358);
constexpr auto SYS_AUDITCTL                       = UntypedConstant(359);
constexpr auto SYS_BSDTHREAD_CREATE               = UntypedConstant(360);
constexpr auto SYS_BSDTHREAD_TERMINATE            = UntypedConstant(361);
constexpr auto SYS_KQUEUE                         = UntypedConstant(362);
constexpr auto SYS_KEVENT                         = UntypedConstant(363);
constexpr auto SYS_LCHOWN                         = UntypedConstant(364);
constexpr auto SYS_BSDTHREAD_REGISTER             = UntypedConstant(366);
constexpr auto SYS_WORKQ_OPEN                     = UntypedConstant(367);
constexpr auto SYS_WORKQ_KERNRETURN               = UntypedConstant(368);
constexpr auto SYS_KEVENT64                       = UntypedConstant(369);
constexpr auto SYS___OLD_SEMWAIT_SIGNAL           = UntypedConstant(370);
constexpr auto SYS___OLD_SEMWAIT_SIGNAL_NOCANCEL  = UntypedConstant(371);
constexpr auto SYS_THREAD_SELFID                  = UntypedConstant(372);
constexpr auto SYS_LEDGER                         = UntypedConstant(373);
constexpr auto SYS_KEVENT_QOS                     = UntypedConstant(374);
constexpr auto SYS_KEVENT_ID                      = UntypedConstant(375);
constexpr auto SYS___MAC_EXECVE                   = UntypedConstant(380);
constexpr auto SYS___MAC_SYSCALL                  = UntypedConstant(381);
constexpr auto SYS___MAC_GET_FILE                 = UntypedConstant(382);
constexpr auto SYS___MAC_SET_FILE                 = UntypedConstant(383);
constexpr auto SYS___MAC_GET_LINK                 = UntypedConstant(384);
constexpr auto SYS___MAC_SET_LINK                 = UntypedConstant(385);
constexpr auto SYS___MAC_GET_PROC                 = UntypedConstant(386);
constexpr auto SYS___MAC_SET_PROC                 = UntypedConstant(387);
constexpr auto SYS___MAC_GET_FD                   = UntypedConstant(388);
constexpr auto SYS___MAC_SET_FD                   = UntypedConstant(389);
constexpr auto SYS___MAC_GET_PID                  = UntypedConstant(390);
constexpr auto SYS_PSELECT                        = UntypedConstant(394);
constexpr auto SYS_PSELECT_NOCANCEL               = UntypedConstant(395);
constexpr auto SYS_READ_NOCANCEL                  = UntypedConstant(396);
constexpr auto SYS_WRITE_NOCANCEL                 = UntypedConstant(397);
constexpr auto SYS_OPEN_NOCANCEL                  = UntypedConstant(398);
constexpr auto SYS_CLOSE_NOCANCEL                 = UntypedConstant(399);
constexpr auto SYS_WAIT4_NOCANCEL                 = UntypedConstant(400);
constexpr auto SYS_RECVMSG_NOCANCEL               = UntypedConstant(401);
constexpr auto SYS_SENDMSG_NOCANCEL               = UntypedConstant(402);
constexpr auto SYS_RECVFROM_NOCANCEL              = UntypedConstant(403);
constexpr auto SYS_ACCEPT_NOCANCEL                = UntypedConstant(404);
constexpr auto SYS_MSYNC_NOCANCEL                 = UntypedConstant(405);
constexpr auto SYS_FCNTL_NOCANCEL                 = UntypedConstant(406);
constexpr auto SYS_SELECT_NOCANCEL                = UntypedConstant(407);
constexpr auto SYS_FSYNC_NOCANCEL                 = UntypedConstant(408);
constexpr auto SYS_CONNECT_NOCANCEL               = UntypedConstant(409);
constexpr auto SYS_SIGSUSPEND_NOCANCEL            = UntypedConstant(410);
constexpr auto SYS_READV_NOCANCEL                 = UntypedConstant(411);
constexpr auto SYS_WRITEV_NOCANCEL                = UntypedConstant(412);
constexpr auto SYS_SENDTO_NOCANCEL                = UntypedConstant(413);
constexpr auto SYS_PREAD_NOCANCEL                 = UntypedConstant(414);
constexpr auto SYS_PWRITE_NOCANCEL                = UntypedConstant(415);
constexpr auto SYS_WAITID_NOCANCEL                = UntypedConstant(416);
constexpr auto SYS_POLL_NOCANCEL                  = UntypedConstant(417);
constexpr auto SYS_MSGSND_NOCANCEL                = UntypedConstant(418);
constexpr auto SYS_MSGRCV_NOCANCEL                = UntypedConstant(419);
constexpr auto SYS_SEM_WAIT_NOCANCEL              = UntypedConstant(420);
constexpr auto SYS_AIO_SUSPEND_NOCANCEL           = UntypedConstant(421);
constexpr auto SYS___SIGWAIT_NOCANCEL             = UntypedConstant(422);
constexpr auto SYS___SEMWAIT_SIGNAL_NOCANCEL      = UntypedConstant(423);
constexpr auto SYS___MAC_MOUNT                    = UntypedConstant(424);
constexpr auto SYS___MAC_GET_MOUNT                = UntypedConstant(425);
constexpr auto SYS___MAC_GETFSSTAT                = UntypedConstant(426);
constexpr auto SYS_FSGETPATH                      = UntypedConstant(427);
constexpr auto SYS_AUDIT_SESSION_SELF             = UntypedConstant(428);
constexpr auto SYS_AUDIT_SESSION_JOIN             = UntypedConstant(429);
constexpr auto SYS_FILEPORT_MAKEPORT              = UntypedConstant(430);
constexpr auto SYS_FILEPORT_MAKEFD                = UntypedConstant(431);
constexpr auto SYS_AUDIT_SESSION_PORT             = UntypedConstant(432);
constexpr auto SYS_PID_SUSPEND                    = UntypedConstant(433);
constexpr auto SYS_PID_RESUME                     = UntypedConstant(434);
constexpr auto SYS_PID_HIBERNATE                  = UntypedConstant(435);
constexpr auto SYS_PID_SHUTDOWN_SOCKETS           = UntypedConstant(436);
constexpr auto SYS_SHARED_REGION_MAP_AND_SLIDE_NP = UntypedConstant(438);
constexpr auto SYS_KAS_INFO                       = UntypedConstant(439);
constexpr auto SYS_MEMORYSTATUS_CONTROL           = UntypedConstant(440);
constexpr auto SYS_GUARDED_OPEN_NP                = UntypedConstant(441);
constexpr auto SYS_GUARDED_CLOSE_NP               = UntypedConstant(442);
constexpr auto SYS_GUARDED_KQUEUE_NP              = UntypedConstant(443);
constexpr auto SYS_CHANGE_FDGUARD_NP              = UntypedConstant(444);
constexpr auto SYS_USRCTL                         = UntypedConstant(445);
constexpr auto SYS_PROC_RLIMIT_CONTROL            = UntypedConstant(446);
constexpr auto SYS_CONNECTX                       = UntypedConstant(447);
constexpr auto SYS_DISCONNECTX                    = UntypedConstant(448);
constexpr auto SYS_PEELOFF                        = UntypedConstant(449);
constexpr auto SYS_SOCKET_DELEGATE                = UntypedConstant(450);
constexpr auto SYS_TELEMETRY                      = UntypedConstant(451);
constexpr auto SYS_PROC_UUID_POLICY               = UntypedConstant(452);
constexpr auto SYS_MEMORYSTATUS_GET_LEVEL         = UntypedConstant(453);
constexpr auto SYS_SYSTEM_OVERRIDE                = UntypedConstant(454);
constexpr auto SYS_VFS_PURGE                      = UntypedConstant(455);
constexpr auto SYS_SFI_CTL                        = UntypedConstant(456);
constexpr auto SYS_SFI_PIDCTL                     = UntypedConstant(457);
constexpr auto SYS_COALITION                      = UntypedConstant(458);
constexpr auto SYS_COALITION_INFO                 = UntypedConstant(459);
constexpr auto SYS_NECP_MATCH_POLICY              = UntypedConstant(460);
constexpr auto SYS_GETATTRLISTBULK                = UntypedConstant(461);
constexpr auto SYS_CLONEFILEAT                    = UntypedConstant(462);
constexpr auto SYS_OPENAT                         = UntypedConstant(463);
constexpr auto SYS_OPENAT_NOCANCEL                = UntypedConstant(464);
constexpr auto SYS_RENAMEAT                       = UntypedConstant(465);
constexpr auto SYS_FACCESSAT                      = UntypedConstant(466);
constexpr auto SYS_FCHMODAT                       = UntypedConstant(467);
constexpr auto SYS_FCHOWNAT                       = UntypedConstant(468);
constexpr auto SYS_FSTATAT                        = UntypedConstant(469);
constexpr auto SYS_FSTATAT64                      = UntypedConstant(470);
constexpr auto SYS_LINKAT                         = UntypedConstant(471);
constexpr auto SYS_UNLINKAT                       = UntypedConstant(472);
constexpr auto SYS_READLINKAT                     = UntypedConstant(473);
constexpr auto SYS_SYMLINKAT                      = UntypedConstant(474);
constexpr auto SYS_MKDIRAT                        = UntypedConstant(475);
constexpr auto SYS_GETATTRLISTAT                  = UntypedConstant(476);
constexpr auto SYS_PROC_TRACE_LOG                 = UntypedConstant(477);
constexpr auto SYS_BSDTHREAD_CTL                  = UntypedConstant(478);
constexpr auto SYS_OPENBYID_NP                    = UntypedConstant(479);
constexpr auto SYS_RECVMSG_X                      = UntypedConstant(480);
constexpr auto SYS_SENDMSG_X                      = UntypedConstant(481);
constexpr auto SYS_THREAD_SELFUSAGE               = UntypedConstant(482);
constexpr auto SYS_CSRCTL                         = UntypedConstant(483);
constexpr auto SYS_GUARDED_OPEN_DPROTECTED_NP     = UntypedConstant(484);
constexpr auto SYS_GUARDED_WRITE_NP               = UntypedConstant(485);
constexpr auto SYS_GUARDED_PWRITE_NP              = UntypedConstant(486);
constexpr auto SYS_GUARDED_WRITEV_NP              = UntypedConstant(487);
constexpr auto SYS_RENAMEATX_NP                   = UntypedConstant(488);
constexpr auto SYS_MREMAP_ENCRYPTED               = UntypedConstant(489);
constexpr auto SYS_NETAGENT_TRIGGER               = UntypedConstant(490);
constexpr auto SYS_STACK_SNAPSHOT_WITH_CONFIG     = UntypedConstant(491);
constexpr auto SYS_MICROSTACKSHOT                 = UntypedConstant(492);
constexpr auto SYS_GRAB_PGO_DATA                  = UntypedConstant(493);
constexpr auto SYS_PERSONA                        = UntypedConstant(494);
constexpr auto SYS_WORK_INTERVAL_CTL              = UntypedConstant(499);
constexpr auto SYS_GETENTROPY                     = UntypedConstant(500);
constexpr auto SYS_NECP_OPEN                      = UntypedConstant(501);
constexpr auto SYS_NECP_CLIENT_ACTION             = UntypedConstant(502);
constexpr auto SYS___NEXUS_OPEN                   = UntypedConstant(503);
constexpr auto SYS___NEXUS_REGISTER               = UntypedConstant(504);
constexpr auto SYS___NEXUS_DEREGISTER             = UntypedConstant(505);
constexpr auto SYS___NEXUS_CREATE                 = UntypedConstant(506);
constexpr auto SYS___NEXUS_DESTROY                = UntypedConstant(507);
constexpr auto SYS___NEXUS_GET_OPT                = UntypedConstant(508);
constexpr auto SYS___NEXUS_SET_OPT                = UntypedConstant(509);
constexpr auto SYS___CHANNEL_OPEN                 = UntypedConstant(510);
constexpr auto SYS___CHANNEL_GET_INFO             = UntypedConstant(511);
constexpr auto SYS___CHANNEL_SYNC                 = UntypedConstant(512);
constexpr auto SYS___CHANNEL_GET_OPT              = UntypedConstant(513);
constexpr auto SYS___CHANNEL_SET_OPT              = UntypedConstant(514);
constexpr auto SYS_ULOCK_WAIT                     = UntypedConstant(515);
constexpr auto SYS_ULOCK_WAKE                     = UntypedConstant(516);
constexpr auto SYS_FCLONEFILEAT                   = UntypedConstant(517);
constexpr auto SYS_FS_SNAPSHOT                    = UntypedConstant(518);
constexpr auto SYS_TERMINATE_WITH_PAYLOAD         = UntypedConstant(520);
constexpr auto SYS_ABORT_WITH_PAYLOAD             = UntypedConstant(521);
constexpr auto SYS_NECP_SESSION_OPEN              = UntypedConstant(522);
constexpr auto SYS_NECP_SESSION_ACTION            = UntypedConstant(523);
constexpr auto SYS_SETATTRLISTAT                  = UntypedConstant(524);
constexpr auto SYS_NET_QOS_GUIDELINE              = UntypedConstant(525);
constexpr auto SYS_FMOUNT                         = UntypedConstant(526);
constexpr auto SYS_NTP_ADJTIME                    = UntypedConstant(527);
constexpr auto SYS_NTP_GETTIME                    = UntypedConstant(528);
constexpr auto SYS_OS_FAULT_WITH_PAYLOAD          = UntypedConstant(529);
constexpr auto SYS_MAXSYSCALL                     = UntypedConstant(530);
constexpr auto SYS_INVALID                        = UntypedConstant(63);

} // namespace gostd::sys::unix
