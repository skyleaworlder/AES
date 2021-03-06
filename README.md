# AES-Cpp

## 一、注意

* 不是彻头彻尾的 `C++`，不妨说是 `C` 风格的 `"C++"`；
* `MixColumns` 使用了快速软件实现算法；
* 暂时只有加密，没有解密；
* 仅支持 128 位；
* 极短时间内完成，必然存在各种各样的差错...

### 1. C 风格的 C++

从文件类型角度，看起来是用 `C++` 实现的 `AES`。

但是实际上只是使用了 `C++ 标准库` 中两个容器类模板：`vector, bitset`。

### 2. MixColumns

最终效果相同，但不是手写的有限域乘法。

如果是作有限域乘法，具体体现在代码中存在一个 `Matrix`，或者直接写出有限域乘法后的情形。

这里的算法如下所示：

```fake
FieldMult(x):

    x = { a_7,a_6,a_5,a_4,a_3,a_2,a_1,a_0 }
    t = a_7
    y = { a_6,a_5,a_4,a_3,a_2,a_1,a_0, 0 }
    y = y ^ 00011011 if t == 1 else y

    return y


MixColumns(c):

    for i <- 0 to 3 do x_j <- s_1_c:
        s_0_c = x_1 ^ x_2 ^ x_3,    s_1_c = x_0 ^ x_2 ^ x_3,
        s_2_c = x_0 ^ x_1 ^ x_3,    s_3_c = x_0 ^ x_1 ^ x_2,

        x_0 = FieldMult(x_0),    x_1 = FieldMult(x_1),
        x_2 = FieldMult(x_2),    x_3 = FieldMult(x_3),

        s_0_c = s_0_c ^ x_0 ^ x_1,    s_1_c = s_1_c ^ x_1 ^ x_2,
        s_2_c = s_2_c ^ x_2 ^ x_3,    s_3_c = s_3_c ^ x_3 ^ x_0,

    return { s_0, s_1, s_2, s_3 }
```

### 3. 没有解密 和 仅支持 128 位

太懒了，以后再说。

## 二、使用

太懒了，就只有个简单的 `main` 函数，并且这个 `main` 函数仅仅支持给定 `128 bits` 长的密钥和明文加密。

根本不存在什么填充。

具体使用，只要直接 `make` 就行了，之后自会产生一个文件到 `./bin` 路径中。
（如果不进行修改的话，是这样。如果修改了，那么就要自己写 `makefile` 了...）

## 三、实际

### 1. 在功能上

这个在密码学角度肯定是干什么都不行的。

但是这点代码实际上是用来描述 [AES Rijndael Cipher explained as a Flash animation](https://www.youtube.com/watch?v=gP4PqVGudtg) 这个 `flash` 动画中的流程的。

也就是说，`flash` 中有的，我都实现了；没有的，我一点都没做。（也就是解密、`128 bits` 以外加密和密钥编排...）

其实实现 `flash` 动画中的过程非常简单。但是我在过程中一直尝试写 **在符合人类审美的基础上尽量简短** 的代码，这花费了很多时间。如果说一共用了 4 个小时，那么花在这上面的时间就得有 2 个小时。

### 2. 在目的上

无论是给出的 `flash`，还是所谓的 **快速软件算法**，都是 **同济大学 2019-2020 春季学期现代密码学课程设计** 题目的一部分。

题目上要求使用 `DES` 产生随机数，用 `AES` 加解密文件，用 `RSA` 进行密钥协商。

但是我 `DES` 写的不好，`AES` 没实现完整，也就 `RSA` 部分还能看。而且写了很久都没有个结果。

这次虽然实现的也不完整，只写了很小一部分。但不妨说是一个晚上的 “赎罪” 吧。
