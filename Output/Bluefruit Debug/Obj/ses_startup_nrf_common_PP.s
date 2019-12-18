# 1 "/home/jbee/Documents/SEGGER Embedded Studio for ARM Projects/Bluefruit/nRF/Device/Startup/ses_startup_nrf_common.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/jbee/Documents/SEGGER Embedded Studio for ARM Projects/Bluefruit/nRF/Device/Startup/ses_startup_nrf_common.s"
# 82 "/home/jbee/Documents/SEGGER Embedded Studio for ARM Projects/Bluefruit/nRF/Device/Startup/ses_startup_nrf_common.s"
  .syntax unified

  .global Reset_Handler



  .extern _vectors
  .extern nRFInitialize
  .global afterInitialize

  .section .init, "ax"
  .thumb_func

  .equ VTOR_REG, 0xE000ED08
  .equ FPU_CPACR_REG, 0xE000ED88





Reset_Handler:


  b nRFInitialize
afterInitialize:



  ldr r0, =__RAM_segment_end__
  ldr r1, =0x7
  bics r0, r1
  mov sp, r0




  ldr r0, =SystemInit
  blx r0
# 145 "/home/jbee/Documents/SEGGER Embedded Studio for ARM Projects/Bluefruit/nRF/Device/Startup/ses_startup_nrf_common.s"
  ldr r0, =VTOR_REG



  ldr r1, =_vectors

  str r1, [r0]




  ldr r0, =FPU_CPACR_REG
  ldr r1, [r0]
  orr r1, r1, #(0xF << 20)
  str r1, [r0]
  dsb
  isb



  b _start
