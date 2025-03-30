# Header-only Variant Project

**Duration:** 2025/03/30 → 2025/03/31  
**Skills:** C++, CMake

---

## 📋 Summary
This project involves creating a custom `Variant` class to replace the `std::variant` class in environments where C++17 is not available. It was specifically designed to parse and manage Style JSON expressions efficiently using modern C++ techniques.

---

## 🛠️ Technology Stack and Libraries

- **Language:**
  - C++
- **Libraries (for testing):**
  - Log Project

---

## 📝 Concept Explanation

### Why Create a Custom Variant?

- **Compatibility:**
  - The `std::variant` class is only available in C++17 and later. This custom solution provides a `Variant` class for projects using earlier C++ standards.

- **Limitations of Type Enum with Union:**
  - A simple type enumeration combined with `union` is a possible alternative. However, this approach restricts types to predefined enum values and requires manual updates when adding new types, leading to scalability issues.

- **Optimized Libraries:**
  - Libraries like Mapbox's Style JSON use custom variant implementations for performance optimization, which inspired this project.

### Key Features of the Variant Class

- **Header-only Implementation:**
  - The project is lightweight and easy to integrate without external dependencies.

- **Template Metaprogramming:**
  - Designed for compile-time type safety and efficiency using techniques like:
    - `EnableIf`
    - `IsSame`
    - Recursive template specialization

- **Aligned Memory Management:**
  - Uses `alignof`, `alignas`, and custom memory structures to manage padding and alignment efficiently, avoiding unnecessary memory overhead.

---

## 🔍 Key Insights from the Project

### Challenges with Type Enum and Union
- Using a type enum requires:
  - Adding a new enum value for each type.
  - Writing additional case-handling logic for each new type.
- The manual overhead makes it unsuitable for dynamic or extensible designs.

### Template Metaprogramming Techniques
1. **Recursive Type Calculations:**
   - Techniques like `SizeCalculator` and `AlignCalculator` recursively calculate the size and alignment of types in a parameter pack.

2. **Alignment (`alignof`):**
   - Determines the required memory alignment for types to ensure efficient memory access and avoid unnecessary padding.

3. **Type Indexing:**
   - The `IndexOf` method identifies the position of a type in the parameter pack for runtime type checking.

4. **Memory Safety:**
   - A custom destroy mechanism ensures proper cleanup of the contained value during destruction.

### Insights into `alignof` and Memory Padding
- **Alignment Basics:**
  - `alignof` retrieves the alignment requirement of a type, determining how memory addresses are calculated for efficient access.

- **Padding Example:**
  - For a struct containing `char` and `int`, memory alignment could require padding:
    - `char` aligns to 1 byte.
    - `int` aligns to 4 bytes.
    - Padding ensures memory accesses align with the larger type, minimizing CPU cycles.

- **Optimization:**
  - Struct fields should be ordered by alignment size to reduce padding and improve performance.

---

## 🚀 Implementation Highlights

### Custom Utilities
- **`EnableIf` and `IsSame`:**
  - Fully implemented without external libraries.

- **Recursive Template Specialization:**
  - `SizeCalculator` and `AlignCalculator` compute size and alignment at compile-time using recursive specialization.

- **TypeList and Matchers:**
  - Used to manage type lists and dynamically match runtime types to compile-time constructs.

### Example Usage of `Variant`
```cpp
#include "Variant.h"

int main() {
    wtr::Variant<int, std::string> variant;

    // Set an integer value
    variant.Set(42);
    std::cout << "Variant contains: " << variant.Get<int>() << std::endl;

    // Set a string value
    variant.Set(std::string("Hello, World!"));
    std::cout << "Variant contains: " << variant.Get<std::string>() << std::endl;

    return 0;
}
```

---

## 🧠 Lessons Learned
- **Template Specialization:**
  - Deep understanding of complete and partial template specialization.
- **Alignment Optimization:**
  - Efficient memory management by leveraging alignment and padding concepts.
- **Compile-time Calculations:**
  - Use of recursive templates for parameter pack processing.

---

## ✨ Future Work
- **Performance Benchmarking:**
  - Compare against `std::variant` in C++17 for runtime efficiency.
- **Error Handling Improvements:**
  - Enhance runtime error reporting when type mismatches occur.
- **Extend Type Support:**
  - Add support for non-trivial types like containers or user-defined structs.

---

## 📜 License
This project is open-source and licensed under the MIT License.

---

## 📂 Project Structure
```
VariantProject/
├── include/
│   └── Variant.h  // Header-only Variant implementation
├── test/
│   └── main.cpp   // Test cases for the Variant class
└── README.md      // Project documentation
```

---

Feel free to contribute or raise issues for further improvements!