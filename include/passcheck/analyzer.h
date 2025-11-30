#ifndef ANALYZER_H
#define ANALYZER_H
#include <stdbool.h>

typedef enum {
  NO_PASSWORD,
  VERY_WEAK,
  WEAK,
  MEDIUM,
  STRONG,
  VERY_STRONG
} StrengthLevel;

typedef struct {
  int score;
  int strength_score;
  int length;
  double entropy;
  bool has_lower;
  bool has_upper;
  bool has_digit;
  bool has_symbol;
  StrengthLevel level;
} PasswordStrength;

PasswordStrength analyze_password(const char *ps);

void calculate_entropy(PasswordStrength *ps);
void determine_strength_level(PasswordStrength *ps);

const char *level_to_string(StrengthLevel level);

#endif
