#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdbool.h>
#include <stddef.h>

// error codes
typedef enum {
  GEN_SUCCESS = 0,
  GEN_ERROR_INVALID_LENGTH = -1,
  GEN_ERROR_NO_CHARSET = -2,
  GEN_ERROR_BUFFER_TOO_SMALL = -3,
  GEN_ERROR_RANDOM_FAILED = -4,
  GEN_ERROR_COMMON_PASSWORD = -5,
  GEN_ERROR_NULL_POINTER = -6
} generator_error_t;

// generation options
typedef struct {
  size_t min_length;
  size_t max_length;
  bool include_lowercase;
  bool include_uppercase;
  bool include_symbols;
  bool check_common;
} generator_options_t;

// default compliant options
void init_generator_options(generator_options_t *opts);

// generate password
generator_error_t generate_password(char *buffer, size_t buffer_size,
                                    size_t length,
                                    const generator_options_t *opts);

// check if its a common password
bool is_common_password(const char *ps);

// initialize generator module
generator_error_t init_generator(const char *data_dir);

// cleanup resourses
void cleanup_generator(void);

// get error message
const char *generator_error_string(generator_error_t err);

#endif
