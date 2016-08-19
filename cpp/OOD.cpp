一、基本概念
 
多重继承是从多于一个直接基类派生类的能力，多重继承的派生类继承其父类的属性。
 
 
class ZooAnimal{
};
class Bear : public ZooAnimal{
};
class Endangered{
};
class Panda : public Bear, public Endangered{
};
 
注意：
 
（1）与单继承一样，只有在定义之后，类才可以用作多重继承的基类。
 
（2）对于类可以继承的基类的数目，没有语言强加的限制，但在一个给定派生列表中，一个基类只能出现一次。
 
 
 
1、多重继承的派生类从每个基类中继承状态
 
Panda ying_yang("ying_yang");
对象ying_yang包含一个Bear子类对象、一个Endangered子类对象以及Panda类中声明的非static数据成员。如下图所示：
 
 
 
 
 
2、派生类构造函数初始化所有基类
 
派生类构造函数可以早构造函数初始化式中给零个或多个基类传递值。
 
Panda::Panda(string name, bool onExhibit)
    : Bear(name, onExhibit, "Panda"),
    Endangered(Endangered::critical){}
构造函数初始化式只能控制用于初始化基类的值，不能控制基类的构造次序。基类构造函数按照基类构造函数在类派生列表中的出现次序调用。对于Panda，基类初始化次序是：
 
（1）ZooAnimal。
 
（2）Bear，第一个直接基类。
 
（3）Endangered，第二个直接基类，它本身没有基类。
 
（4）Panda，初始化本身成员，然后运行它的构造函数的函数体。
 
注意：构造函数调用次序既不受构造函数初始化列表中出现的基类的影响，也不受基类在构造函数初始化列表中的出现次序的影响。例如：
 
Panda::Panda() : Endangered(Endangered::critical){}
这个构造函数将隐式调用Bear的默认构造函数，尽管它不出现在构造函数初始化列表中，但仍然在Endangered类构造函数之前调用。
 
3、析构的次序
 
按照构造函数运行的逆序调用析构函数。Panda、Endangered、Bear，ZooAnimal。
 
 
 
二、转换与多个基类
 
单个基类情况下，派生类的指针或引用可自动转换为基类的指针或引用。对于多重继承，派生类的指针或引用可以转换为其任意基类的指针或引用。
 
注意：在多重继承情况下，遇到二义性转换的可能性更大。编译器不会试图根据派生类转换来区别基类间的转换，转换到每个基类都一样好。例如：
 
void print(const Bear&);
void print(const Endangered&);
通过Panda对象调用print时，会导致一个编译时错误。
 
1、基于指针或引用类型的查找
 
与单继承一样，用基类的指针或引用只能访问基类中定义（或继承）的成员，不能访问派生类中引入的成员。当一个类派生于多个基类的时候，那些基类之间没有隐含的关系，不允许使用一个基类的指针访问其他基类的成员。例如：
 
 
class ZooAnimal
{
public:
    virtual void print(){}
    virtual ~ZooAnimal(){}
};
class Bear : public ZooAnimal
{
public:
    virtual void print()
    {
        cout << "I am Bear" << endl;
    }
    virtual void toes(){}
};
class Endangered
{
public:
    virtual void print(){}
    virtual void highlight()
    {
        cout << "I am Endangered.highlight" << endl;
    }
    virtual ~Endangered(){}
};
class Panda : public Bear, public Endangered
{
public:
    virtual void print()
    {
        cout << "I am Panda" << endl;
    }
    virtual void highlight()
    {
        cout << "I am Panda.highlight" << endl;
    }
    virtual void toes(){}
    virtual void cuddle(){}
    virtual ~Panda()
    {
        cout << "Goodby Panda" << endl;
    }
};
 
当有如下调用发生时：
 
 
int main()
{
    Bear *pb = new Panda();
    pb->print();            //ok: Panda::print
//    pb->cuddle();            //error: not part of Bear interface
//    pb->highlight();        //error: not part of Bear interface
    delete pb;                //Panda::~Panda
 
    Endangered *pe = new Panda();
    pe->print();            //ok: Panda::print
//    pe->toes();                //error: not part of Endangered interface
//    pe->cuddle();            //error: not part of Endangered interface
    pe->highlight();        //ok: Panda::highlight
    delete pe;                //Panda::~Panda
 
    return 0;
}
 
 
 
2、确定使用哪个虚析构函数
 
我们假定所有根基类都将它们的析构函数定义为虚函数，那么通过下面几种删除指针方法，虚析构函数处理都是一致的。
 
delete pz;            //pz is a ZooAnimal*
delete pb;            //pb is a Bear*
delete pp;            //pp is a Panda*
delete pe;            //pe is a Endangered*
假定上面四个指针都指向Panda对象，则每种情况发生完全相同的析构函数调用次序，即与构造次序是逆序的：通过虚机制调用Panda析构函数，再依次调用Endangered、Bear，ZooAnimal的析构函数。
 
 
 
三、多重继承派生类的复制控制
 
多重继承的派生类使用基类自己的复制构造函数、赋值操作符，析构函数隐式构造、赋值或撤销每个基类。下面我们做几个小实验：
 
 
 1 class ZooAnimal
 2 {
 3 public:
 4     ZooAnimal()
 5     {
 6         cout << "I am ZooAnimal default constructor" << endl;
 7     }
 8     ZooAnimal(const ZooAnimal&)
 9     {
10         cout << "I am ZooAnimal copy constructor" << endl;
11     }
12     virtual ~ZooAnimal()
13     {
14         cout << "I am ZooAnimal destructor" << endl;
15     }
16     ZooAnimal& operator=(const ZooAnimal&)
17     {
18         cout << "I am ZooAnimal copy operator=" << endl;
19 
20         return *this;
21     }
22 };
23 class Bear : public ZooAnimal
24 {
25 public:
26     Bear()
27     {
28         cout << "I am Bear default constructor" << endl;
29     }
30     Bear(const Bear&)
31     {
32         cout << "I am Bear copy constructor" << endl;
33     }
34     virtual ~Bear()
35     {
36         cout << "I am Bear destructor" << endl;
37     }
38     Bear& operator=(const Bear&)
39     {
40         cout << "I am Bear copy operator=" << endl;
41 
42         return *this;
43     }
44 };
45 class Endangered
46 {
47 public:
48     Endangered()
49     {
50         cout << "I am Endangered default constructor" << endl;
51     }
52     Endangered(const Endangered&)
53     {
54         cout << "I am Endangered copy constructor" << endl;
55     }
56     virtual ~Endangered()
57     {
58         cout << "I am Endangered destructor" << endl;
59     }
60     Endangered& operator=(const Endangered&)
61     {
62         cout << "I am Endangered copy operator=" << endl;
63 
64         return *this;
65     }
66 };
67 class Panda : public Bear, public Endangered
68 {
69 public:
70     Panda()
71     {
72         cout << "I am Panda default constructor" << endl;
73     }
74     Panda(const Panda&)
75     {
76         cout << "I am Panda copy constructor" << endl;
77     }
78     virtual ~Panda()
79     {
80         cout << "I am Panda destructor" << endl;
81     }
82     Panda& operator=(const Panda&)
83     {
84         cout << "I am Panda copy operator=" << endl;
85         
86         return *this;
87     }
88 };
 
还是前面的类，只不过我将没有必要的虚函数去掉了。下面我执行以下操作：
 
 
int main()
{
    cout << "TEST 1" << endl;
    Panda ying_ying;
    cout << endl << endl;
    
    cout << "TEST 2" << endl;
    Panda zing_zing = ying_ying;
    cout << endl << endl;
 
    cout << "TEST 3" << endl;
    zing_zing = ying_ying;
    cout << endl << endl;
    
    return 0;
}
 
 
 
这个结果是毫无疑问的，先调用基类构造函数，再调用派生类。
 
 
 
 
 
首先调用默认构造函数构造一个zing_zing对象，然后调用拷贝构造函数，将ying_ying拷贝至zing_zing。注意：这里用的是拷贝构造函数，而不是赋值操作符，那什么时候用赋值操作符呢？我们接着看TEST3的结果：
 
 
 
这种情况才调用赋值操作符：就是两个对象都已经分配内存后，再进行赋值。这里有个疑问，基类也定义了operator=了，为什么不调用基类的operator=呢？我们将Panda类的operator=注释掉，重新来做TEST3，好玩的结果出现了：
 
 
 
Panda的合成赋值操作符调用了两个基类的operator=。
 
我们得出以下结论：如果派生类定义了自己的复制构造函数或赋值操作符，则负责复制（赋值）所有的基类子部分，而不再调用基类相应函数。只有派生类使用合成版本的复制构造函数或赋值操作符，才自动调用基类部分相应的函数。
 
最后我们来看一下析构函数的表现：
 
 
 
析构函数的行为是符合我们预期的，这里有一点我没有体现出来就是zing_zing是ying_ying之后定义的对象，所以zing_zing的构造函数先执行（前4行），后4行代表ying_ying构造函数的执行。如果具有多个基类的类定义了自己的析构函数，则该析构函数只负责清除派生类。
 
 
 
四、多重继承下的类作用域
 
在多重继承下，多个基类作用域可以包围派生类作用域。查找时，同时检查所有基类继承子树，例如：并行查找Endangered和Bear/ ZooAnimal子树。如果在多个子树上找到该名字，那个名字必须显式指定使用哪个基类。否则，该名字的使用是二义性的。
 
例如：Endangered类和Bear类都有print函数，则ying_ying.print()将导致编译时错误。
 
注意：
 
（1）Panda类的派生导致有两个名为print的成员是合法的。派生只是导致潜在的二义性，如果没有Panda对象调用print，就可避免这个二义性。你可以Bear::print或Endangered::print来调用。
 
（2）当然，如果只在一个基类子树上找到声明是不会出错的。
 
下面仍然有个小实验要做：
 
 
class ZooAnimal
{
public:
    //void print(int x){}
};
class Bear : public ZooAnimal
{
public:
    void print(int x){}
};
class Endangered
{
public:
    void print(){}
};
class Panda : public Bear, public Endangered
{
public:
};
 
TEST1：将两个基类Bear和Endangered两个print的形参表设为不同。
 
TEST2：将Bear中的print去掉，在ZooAnimal中增加print。
 
TEST3：将Endangered中print设置为private访问。
 
以上三种情况下，当我这样调用ying_ying.print()或ying_ying.print(1)时，都显示编译时错误（二义性）。
 
我们的得出这样的结论：名字查找的过程是这样的，首先编译器找到一个匹配的声明（找到两个匹配的声明，这导致二义性），然后编译器才确定所找到的声明是否合法。
 
所以说，当我们调用这样的函数时，应该这样ying_ying.Bear::print()。