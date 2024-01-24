#ifndef S21_CALCULATOR_CONTROLLER_H_
#define S21_CALCULATOR_CONTROLLER_H_

#include "../model/s21_calculator.h"
#include "../model/s21_model.h"
#include "../model/s21_polish_notation.h"

namespace s21 {
class CalculatorController {
 public:
  explicit CalculatorController() {}
  ~CalculatorController() {}
  Status calculate_converted_expression(std::string &str, double &x,
                                        double &res) noexcept;
  Status calculate(std::string &str, double &x, double &res) noexcept;
  Status ToPolishNotation(const std::string &str, std::string &res) noexcept;
};
}  // namespace s21

#endif  // S21_CALCULATOR_CONTROLLER_H_