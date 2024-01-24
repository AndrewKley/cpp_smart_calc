#ifndef S21_CALCULATOR_H_
#define S21_CALCULATOR_H_

#include <cmath>

#include "./s21_model.h"
#include "./s21_polish_notation.h"

namespace s21 {

class Calculator {
 public:
  explicit Calculator() {}
  ~Calculator() {}
  Status calculate_converted_expression(std::string &str, double &x,
                                        double &res) noexcept;
  Status calculate(std::string &str, double &x, double &res) noexcept;

 private:
  double s21_atof(const std::string &str, size_t &i) noexcept;
  Status is_nan(double num, char operation) const noexcept;
  int is_unary_operator(char operation) const noexcept;
  int take_operation(char ch) const noexcept;
  double switch_arithmetic(double num1, double num2,
                           char operation) const noexcept;
  double switch_unary(double num, char operation) const noexcept;
  Status calculate_double(std::stack<double> &st, char operation,
                          double &res) noexcept;
  Status calculate_unary(std::stack<double> &st, char operation,
                         double &res) noexcept;
};

}  // namespace s21

#endif  // S21_CALCULATOR_H_