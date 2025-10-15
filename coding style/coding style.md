# 空白字符

1. 行末不能有尾随空白。
2. 使用水平制表符（Tab）进行缩进。==?==
3. 在以下情况下__不要__使用空格：
   - 模板的尖括号内（`vector<int>`，而不是 `vector< int >` 或 `vector <int>`）
   - 一元运算符（`!`、`--`、`++`、`-`、`+`）之后
   - 后缀运算符（`--` 和 `++`）之前
   - 成员运算符（`.`、`->`）之后
4. 在以下情况中**必须**使用空白：
   - 分号（`;`）、逗号（`,`）之后
   - 二元运算符（例如 `*`、`+`）和比较运算符周围
   - 赋值运算符（例如 `=`、`+=`）周围
   - 三元条件运算符（`?` 和 `:`）周围
   - 关键字（如 `if`、`for`、`while`、`switch`、`return` 等）周围
5. 不要在函数名和左括号之间加空格。(`fun()`而不是`fun ()`)

# 缩进

1. 基本缩进单位为 4 个空格。 ==?==

2. 每个块级（由 `{` 和 `}` 包围）增加一级缩进，例如：

   ```c++
   if (x > 0)
   {
   	r = -x;
   }
   else
   {
       r = x;
   }
   ```

3. `case` 标签应比其所在的 `switch` 语句缩进一级，例如：

   ```c++
   switch (op)
   {
       case '+':
           addOperands(x, y);
           break;
       default:
           ERROR();
   }
   ```

# 大括号 (Allman 风格) ==?==

1. 所有 `if`、`while`、`do`、`for` 语句和函数定义都__必须__使用大括号，且左大括号单独一行。

2. 右大括号单独一行，与匹配的左大括号对齐。

3. 示例：

   ```c++
   if (x > 0)
   {
       y = -x;
   }
   else
   {
       y = x;
   }
   
   for (int i = 0; i < 10; ++i)
   {
       std::cout << i << std::endl;
   }
   
   void myFunction(int arg)
   {
       // 函数体
   }
   ```

# 注释

1. 函数应该使用注释说明其行为、参数和返回值。

2. 注释用都中文写，`@brief`等除外。==?==

3. TODO注释：标记待完成事项，内容需准确详细
   ```c++
   好：// TODO: 这个函数/部分的条件判断逻辑有错误，……
   不好：// TODO: 有bug，要修复
   ```

4. 返回非 `void` 值的函数必须在其注释中描述返回值。

5. 使用 Doxygen 风格的注释文档：==?==

   ```c++
   /**
    * @brief 简短描述（通常1句话，说明核心功能）
    * 
    * 详细描述（可选，补充实现逻辑、注意事项、使用场景等）
    * - 可以用列表增强可读性
    * - 支持换行和特殊符号（如公式、链接）
    * 
    * @param  参数名 参数说明（描述参数含义、取值范围、是否可为空等）
    * @param  另一个参数名 另一个参数的说明
    * @return 返回值说明（描述返回值的含义、可能的取值）
    * @note   额外提示（如“此函数线程不安全”“需要提前初始化XXX”）
    * @warning 警告信息（如“传入负数会导致异常”）
    */
   int add(int a, int b)
   {
       return a + b;
   }
   ```

   __注释中的有些参数并非必须，如note，warning...__

# 命名

1. 常量（`const` 或 `constexpr`）必须全部大写（例如 `MAX_SIZE`、`DEFAULT_NAME`）。
2. 参数、局部变量和函数名使用驼峰命名法（camelCase）==?==
3. 类型（类、结构体、枚举、类型别名）名使用帕斯卡命名法（PascalCase）==?==
4. 成员变量使用 `_` 前缀。==?==
5. 命名空间使用蛇形命名法`namespace my_project `

# 头文件

1. 使用 `#pragma once` 头文件保护宏。==?==

2. 按以下顺序组织头文件包含：__请注意：`< >`和`" "`的正确使用__ ==?==

   ```c++
   // main.cpp 示例
   // 1. 对应头文件（如果有）
   #include "main.h"
   
   // 2. C 系统头文件
   #include <cassert>
   #include <cmath>
   
   // 3. C++ 系统头文件  
   #include <vector>
   #include <string>
   #include <memory>
   
   // 4. 其他库头文件
   // 5. 本项目头文件
   #include "graph.h"
   #include "dijkstra.h"
   #include "heaps/binary_heap.h"
   ```

   

3. 不要包含未使用的头文件。

# 其他

1. 使用 `nullptr` 而不是 `NULL`。

2. 使用 `using` 别名而不是 `typedef`。

3. 优先使用 `enum class` 而不是普通 `enum`。

4. 使用 `auto` 关键字来避免冗长的类型声明，但要确保代码可读性。==?==

5. 使用智能指针（`unique_ptr`、`shared_ptr`）而不是原始指针。==?==

6. 避免使用宏，优先使用 `constexpr`、`inline` 函数和模板。==?==

7. 如果类允许，使用范围-based for 循环：==?==

   ```c++
   for (const auto& item : container)
   {
       // 仅读取 item 的值
   }
   
   for (int& num : numbers) // 使用引用
   {
       num *= 2; // 将每个元素乘以 2
   }
   ```

   

8. 在条件语句中使用括号明确优先级：

   ```c++
   if ((a && b) || c)  // 好
   if (a && b || c)    // 不好
   ```

9. 每个 `switch` 语句都应包含 `default` 分支。

10. 每个 `switch` 分支应以 `break` 语句结束，或者使用 `[[fallthrough]]` 属性明确表示穿透。==?==    __[[fallthrough]] 从 C++17 标准开始引入，注意版本__

11. 使用 `override` 关键字明确重写虚函数。==?==

12. 使用 `static_cast`, `const_cast` 等显式转换，禁用C风格强制转换。

# 类

1. 遵循 RAII原则。==?这个可能有点麻烦==

2. 如果类管理资源，需定义或删除拷贝构造函数、拷贝赋值运算符、移动构造函数、移动赋值运算符。==?可能有点麻烦==

3. 将成员变量设为私有，通过公有成员函数访问。

4. 使用成员初始化列表：

   ```c++
   class MyClass
   {
   public:
       MyClass(int value) : m_value(value)
       {
           ...
       }
   
   private:
       int _value;
   };
   ```

# 限制

1. 单个文档不要超过2000行。
2. 每行不要超过100个字符。
3. 每个函数不要超过80行。
4. 每个函数的参数不要超过8个。
5. 类的层次深度不应超过 4 层。



# 作用域

1. 头文件中严禁任何的`using`

2. 在源文件中，使用`using std::cout;`或`std::cout`，而非`using namespace std;`

   ```c++
   using std::cout;
   using std::endl;
   using std::string;
   ...
   ```

# 示例

```c++
#include <iostream>
#include <vector>

using std::......;

class Calculator
{
public:
    /**
     * @brief 计算两个数的和
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两个操作数的和
     */
    int add(int a, int b)
    {
        return a + b;
    }
    
    /**
     * @brief 计算阶乘
     * @param n 要计算阶乘的数
     * @return n 的阶乘
     */
    int factorial(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        
        int result = 1;
        for (int i = 2; i <= n; ++i)
        {
            result *= i;
        }
        return result;
    }

private:
    int _cache;
};

int main()
{
    Calculator calc;
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    for (const auto& num : numbers)
    {
        std::cout << "Factorial of " << num << " is " 
                  << calc.factorial(num) << std::endl;
    }
    
    return 0;
}
```

# End

写的太多了，对不起(＞人＜；)

如果发现有的代码风格和你的习惯不一样的话，及时沟通，切勿感到有压力。

如果有任何细节不明白，也请及时沟通，我表达能力不太行。

任然有很多细节没写在这个上面，这个文档会上传到 github 上，到时候我们可以一边做project一边完善。