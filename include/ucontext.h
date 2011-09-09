#ifndef ANDROID
#include_next <ucontext.h>
#else

#ifndef UCONTEXT_H
#define UCONTEXT_H 1

#include <signal.h>

/* Number of each register is the `gregset_t' array.  */
enum
{
  R0 = 0,
#define R0      R0
  R1 = 1,
#define R1      R1
  R2 = 2,
#define R2      R2
  R3 = 3,
#define R3      R3
  R4 = 4,
#define R4      R4
  R5 = 5,
#define R5      R5
  R6 = 6,
#define R6      R6
  R7 = 7, 
#define R7      R7
  R8 = 8,
#define R8      R8
  R9 = 9,
#define R9      R9
  R10 = 10, 
#define R10     R10
  R11 = 11,
#define R11     R11
  R12 = 12,
#define R12     R12
  R13 = 13,
#define R13     R13
  R14 = 14,
#define R14     R14
  R15 = 15
#define R15     R15
};

struct sigcontext {
 unsigned long trap_no;
 unsigned long error_code;
 unsigned long oldmask;
 unsigned long arm_r0;
 unsigned long arm_r1;
 unsigned long arm_r2;
 unsigned long arm_r3;
 unsigned long arm_r4;
 unsigned long arm_r5;
 unsigned long arm_r6;
 unsigned long arm_r7;
 unsigned long arm_r8;
 unsigned long arm_r9;
 unsigned long arm_r10;
 unsigned long arm_fp;
 unsigned long arm_ip;
 unsigned long arm_sp;
 unsigned long arm_lr;
 unsigned long arm_pc;
 unsigned long arm_cpsr;
 unsigned long fault_address;
};

typedef struct sigcontext mcontext_t;

# define _SIGSET_NWORDS (1024 / (8 * sizeof (unsigned long int)))
typedef struct
  {
    unsigned long int __val[_SIGSET_NWORDS];
  } __sigset_t;

typedef struct ucontext
  {
    unsigned long uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    unsigned long uc_regspace[128] __attribute__((__aligned__(8)));
  } ucontext_t;

#endif
#endif /* ANDROID */
