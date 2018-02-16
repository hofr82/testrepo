#include <cstdint>
#include <iostream>

class CompIdx {
 public:
  enum Enum : uint8_t { FC, RC, VFC };

  CompIdx(Enum const idx) : value_(idx) {}

  operator uint8_t() const { return static_cast<uint8_t>(value_); };
  void dummyF(uint8_t const x);

 private:
  Enum value_;
};

void test(CompIdx const idx) {
  idx.dummyF();
  switch (idx) {
    case CompIdx::FC: {
      std::cout << "FC compartment\n";
      break;
    }
    case CompIdx::RC: {
      std::cout << "RC compartment\n";
      break;
    }
    case CompIdx::VFC: {
      std::cout << "VFC compartment\n";
      break;
    }
    default: {
      std::cout << "Undefined compartment\n";
      break;
    }
  }
}

int main(void) {
  test(CompIdx(CompIdx::VFC));
  test(CompIdx(CompIdx::FC));
  test(CompIdx(CompIdx::RC));
  test(CompIdx(static_cast<CompIdx::Enum>(5)));

  static_assert(sizeof(CompIdx) == 1);

  for (int i = 0; i <= 100; ++i) {
    auto isFizz = !(i % 3);
    auto isBuzz = !(i % 5);

    if (isFizz && isBuzz) {
      std::cout << "FizzBuzz\n";
    } else if (isFizz) {
      std::cout << "Fizz\n";
    } else if (isBuzz) {
      std::cout << "Buzz\n";
    } else {
      std::cout << i << "\n";
    }
  }

  return 0;
}