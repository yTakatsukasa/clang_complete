#pragma once

//#if defined(__CUDA__) && defined(__clang__)
//#include <__clang_cuda_math_forward_declares.h>

#pragma push_macro("__DEVICE__")
#define __DEVICE__                                                             \
  extern  __attribute__((device))

__DEVICE__ int __nvvm_read_ptx_sreg_tid_x();
__DEVICE__ int __nvvm_read_ptx_sreg_tid_y();
__DEVICE__ int __nvvm_read_ptx_sreg_tid_z();
__DEVICE__ int __nvvm_read_ptx_sreg_ctaid_x();
__DEVICE__ int __nvvm_read_ptx_sreg_ctaid_y();
__DEVICE__ int __nvvm_read_ptx_sreg_ctaid_z();
__DEVICE__ int __nvvm_read_ptx_sreg_ntid_x();
__DEVICE__ int __nvvm_read_ptx_sreg_ntid_y();
__DEVICE__ int __nvvm_read_ptx_sreg_ntid_z();
__DEVICE__ int __nvvm_read_ptx_sreg_nctaid_x();
__DEVICE__ int __nvvm_read_ptx_sreg_nctaid_y();
__DEVICE__ int __nvvm_read_ptx_sreg_nctaid_z();


//__clang_cuda_device_functions.h
__DEVICE__ int __nvvm_vote_all(int);
__DEVICE__ int __nvvm_vote_any(int);
__DEVICE__ unsigned int __nvvm_vote_ballot(int);
__DEVICE__ double __nvvm_atom_add_gen_d(double *__p, double __v);
__DEVICE__ double __nvvm_atom_cta_add_gen_d(double *__p, double __v);
__DEVICE__ double __nvvm_atom_sys_add_gen_d(double *__p, double __v);
__DEVICE__ float __nvvm_atom_add_gen_f(float *__p, float __v);
__DEVICE__ float __nvvm_atom_cta_add_gen_f(float *__p, float __v);
__DEVICE__ float __nvvm_atom_sys_add_gen_f(float *__p, float __v);
__DEVICE__ float __nvvm_atom_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_add_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_add_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_add_gen_i(int *__p, int __v);

__DEVICE__ int __nvvm_atom_and_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_and_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_and_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cas_gen_i(int *__p, int __cmp, int __v);
__DEVICE__ int __nvvm_atom_cta_cas_gen_i(int *__p, int __cmp, int __v);
__DEVICE__ int __nvvm_atom_sys_cas_gen_i(int *__p, int __cmp, int __v);
//__DEVICE__ int __nvvm_atom_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_xchg_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_max_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_max_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_max_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_min_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_min_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_min_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_or_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_or_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_or_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_xor_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_cta_xor_gen_i(int *__p, int __v);
__DEVICE__ int __nvvm_atom_sys_xor_gen_i(int *__p, int __v);
__DEVICE__ long long __nvvm_atom_max_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_cta_max_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_sys_max_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_min_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_cta_min_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_sys_min_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_and_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_cta_and_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_sys_and_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_or_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_cta_or_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_sys_or_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_xor_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_cta_xor_gen_ll(long long *__p, long long __v);
__DEVICE__ long long __nvvm_atom_sys_xor_gen_ll(long long *__p, long long __v);

__DEVICE__ unsigned int __nvvm_read_ptx_sreg_pm0(void);
__DEVICE__ unsigned int __nvvm_read_ptx_sreg_pm1(void);
__DEVICE__ unsigned int __nvvm_read_ptx_sreg_pm2(void);
__DEVICE__ unsigned int __nvvm_read_ptx_sreg_pm3(void);
__DEVICE__ int __nvvm_bar0_and(int __a);
__DEVICE__ int __nvvm_bar0_popc(int __a);
__DEVICE__ int __nvvm_bar0_or(int __a);
__DEVICE__ void __nvvm_membar_gl(void);
__DEVICE__ void __nvvm_membar_cta(void);
__DEVICE__ void __nvvm_membar_sys(void);
__DEVICE__ unsigned int __nvvm_atom_add_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_add_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_add_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_and_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_and_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_and_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cas_gen_i(int *__p, unsigned int __cmp, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_cas_gen_i(int *__p, unsigned int __cmp, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_cas_gen_i(int *__p, unsigned int __cmp, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_dec_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_dec_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_dec_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_xchg_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_xchg_gen_i(int *__p, unsigned int __v);

__DEVICE__ unsigned int __nvvm_atom_sys_xchg_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_inc_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_inc_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_inc_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_max_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_max_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_max_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_min_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_min_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_min_gen_ui(unsigned int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_or_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_or_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_or_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_xor_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_cta_xor_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned int __nvvm_atom_sys_xor_gen_i(int *__p, unsigned int __v);
__DEVICE__ unsigned long long __nvvm_atom_add_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_add_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_add_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_and_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_and_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_and_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cas_gen_ll(long long *__p, unsigned long long __cmp, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_cas_gen_ll(long long *__p, unsigned long long __cmp, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_cas_gen_ll(long long *__p, unsigned long long __cmp, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_xchg_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_xchg_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_xchg_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_max_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_max_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_max_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_min_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_min_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_min_gen_ull(unsigned long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_or_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_or_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_or_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_xor_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_cta_xor_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ unsigned long long __nvvm_atom_sys_xor_gen_ll(long long *__p, unsigned long long __v);
__DEVICE__ int __nvvm_read_ptx_sreg_clock();
__DEVICE__ long long __nvvm_read_ptx_sreg_clock64();

__DEVICE__ void __syncthreads();

#pragma pop_macro("__DEVICE__")

#undef __CLANG_CUDA_RUNTIME_WRAPPER_H__
//Skip loading __clang_cuda_intrinsics.h
#define __CLANG_CUDA_INTRINSICS_H__

#ifdef __host__
#error "defined"
#undef __host__
#endif

#pragma clang diagnostic push
#pragma diagnostic ignored "-Wall -Wextra -Weverything"
#include <__clang_cuda_runtime_wrapper.h>
#pragma clang diagnostic pop
