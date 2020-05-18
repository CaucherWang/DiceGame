## 主要区别

- 大致对应关系：

  - Game <-> DiceGamePlatform
  - GameSession <-> GameTable
  - Player <-> User

- 参考实现没有和Command, message有关的类

- Player, User 两个类没有分开

- Dice类

  - TestDice的存在
  - 用到两个

  - 为Player所有还是为GameSession所有，

- 没有Turn，Round两个类（但是Player里有SessionState）

- 是否将实现留在main和类外部

- Strategy的实现方法

## 修改意见



- 将Player, User类分开实现完善逻辑关系
- Dice等类继承使用接口
- Turn, Round作为Player、GameSession的成员而不是单独类。
- Strategy在Player里写成一个单件

![class_diagram](/Users/apple/Desktop/2020Spring/OO/DiceGame/class_diagram.jpeg)