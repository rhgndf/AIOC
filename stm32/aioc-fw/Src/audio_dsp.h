#ifndef AUDIO_DSP_H_
#define AUDIO_DSP_H_

#include <stdint.h>

typedef struct {
	uint32_t sum;
	uint32_t integer_rate;
	uint32_t frac_rate_n, frac_rate_d;
	uint32_t current_sample;
	uint32_t output_samples;
	uint32_t output_buffer[128];
} rational_decimator_t;

void rational_decimator_init(rational_decimator_t* rd);
void rational_decimator_reset(rational_decimator_t* rd);
void rational_decimator_set_rate(rational_decimator_t* rd, uint32_t input_rate, uint32_t output_rate);
uint32_t rational_decimator_get_integer_rate(rational_decimator_t* rd);
uint32_t rational_decimator_process_block_u16(rational_decimator_t* rd, uint16_t* buf, uint32_t len);
uint32_t* rational_decimator_get_outputs(rational_decimator_t* rd);

#endif
