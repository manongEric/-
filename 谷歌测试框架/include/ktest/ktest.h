/*************************************************************************
	> File Name: ktest.h
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Aug 2022 11:24:24 PM CST
 ************************************************************************/

#ifndef _KTEST_H
#define _KTEST_H
#include<vector>
#include<assert.h>
#include<string>
#include<sstream>
#include<mutex>
using namespace std;
//TestBase 仅代表测试用例粗略信息
class TestBase {
public:
    virtual void TestBody() = 0;//所有测试用例执行的过程
    virtual ~TestBase(){}
};
class TestFactoryBase {
public:
    virtual TestBase *getObject() = 0; // 生成测试用例的对象
    virtual void destory(TestBase* ) = 0;
};

template<class CLASS_T> //运用模板，每个类型的测试用例只需要一个工厂,兼容性
class TestFactoryImpl : public TestFactoryBase {
public:
    TestBase *getObject() override {
        return new CLASS_T();
    }
    void destory(TestBase *test_unit) override{
        assert(dynamic_cast<CLASS_T *>(test_unit) != nullptr);//测试用例类型和classT一样才能销毁
        delete test_unit;
        return;
    }
};

class TestInfo;
class TestUnit {
public:
    static TestUnit* GetInstance();

    void AddTestInfo(TestInfo* test_info);//全局唯一一个方法
    void setTestInfo(TestInfo* test_info);
    TestInfo* getTestInfo();
    vector<TestInfo *>::iterator begin();//为了外部遍历存储区方便,迭代可存储的测试用例
    vector<TestInfo *>::iterator end();
private:
    TestInfo* test_info;
    vector<TestInfo *> test_info_arr;
    TestUnit(){}
    TestUnit(const TestUnit &) = delete;

    static std::mutex m_mutex;
    static TestUnit *singel;
};

class TestInfo{//记录测试用例的详细信息
public:
    TestInfo(
        const char* test_suit_name,
        const char* test_name, 
        TestFactoryBase* factory
    ) : test_suit_name(test_suit_name), test_name(test_name), factory(factory) {}
    
    void run() {//运行当前测试用例
        TestUnit::GetInstance()->setTestInfo(this);
        TestBase* test_unit = factory->getObject();
        cout << "[   RUN   ]" << test_suit_name << "." << test_name << endl;   
        run_flag = true;
        test_unit->TestBody();
        if (run_flag) {
            cout <<"[   OK    ]";
        } else {
            cout <<"[   FAILED   ]";
        }
        cout << test_suit_name << "." << test_name << endl;
        factory->destory(test_unit);
        TestUnit::GetInstance()->setTestInfo(nullptr);
        return;
        }
    bool run_flag;

private:
    const char* test_suit_name;
    const char* test_name;
    TestFactoryBase* factory;
};

void TestUnit::AddTestInfo(TestInfo* test_info) {//全局唯一一个方法
    test_info_arr.push_back(test_info);
    return;
}

TestInfo* TestUnit::getTestInfo() {return test_info;}
void TestUnit::setTestInfo(TestInfo* test_info) {this->test_info = test_info;}
vector<TestInfo *>::iterator TestUnit::begin() {return test_info_arr.begin();}//为了外部遍历存储区方便,迭代可存储的测试用例
vector<TestInfo *>::iterator TestUnit::end() {return test_info_arr.end();}

TestUnit* TestUnit::singel = nullptr;
std:: mutex TestUnit::m_mutex;

TestUnit *TestUnit::GetInstance() {
    if (singel == nullptr) {
        unique_lock<mutex> lock(m_mutex);
        if (singel == nullptr) {
            singel = new TestUnit();
        }
    }
    return singel;
}
TestInfo* MakeAndRegisterTestInfo (
    const char* test_suit_name, 
    const char* test_name,
    TestFactoryBase* factory //实参传递 具体生产某种类型的工厂
    ) {
        TestInfo* test_info = new TestInfo(test_suit_name, test_name, factory);
        //singel : 存储每一个测试用例信息，给RUN_ALL_TEST使用
        TestUnit::GetInstance()->AddTestInfo(test_info);
        return test_info;
    }
class CompareMsg {
public :
    CompareMsg() : __msg("") {}
    template<typename T, typename U>
    CompareMsg (
        const char* str_a,
        const char* str_comp,
        const char* str_b,
        const T &a, const U &b,
        const char* file_name,
        int position
        ) {
            stringstream ss;
            ss << file_name << ":" << position << ": Failure" << endl;
            ss << "Expected : (" << str_a << ")" << str_comp << " (" << str_b << "), ";
            ss << "actual: " << a << " vs " << b << endl;
            __msg = ss.str();
        }
    operator bool() {
        return __msg != "";
    }
    string msg() {return __msg;}
private:
    string __msg;
};
template<typename T, typename U>
CompareMsg CompareEQ(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a == b) return CompareMsg();
        return CompareMsg(str_a, "==", str_b, a, b, file_name, position);
    }

template<typename T, typename U>
CompareMsg CompareNE(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a != b) return CompareMsg();
        return CompareMsg(str_a, "!=", str_b, a, b, file_name, position);
    }


template<typename T, typename U>
CompareMsg CompareLT(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a < b) return CompareMsg();
        return CompareMsg(str_a, "<", str_b, a, b, file_name, position);
    }


template<typename T, typename U>
CompareMsg CompareLE(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a <= b) return CompareMsg();
        return CompareMsg(str_a, "<=", str_b, a, b, file_name, position);
    }


template<typename T, typename U>
CompareMsg CompareGT(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a > b) return CompareMsg();
        return CompareMsg(str_a, ">", str_b, a, b, file_name, position);
    }

template<typename T, typename U>
CompareMsg CompareGE(
    const T &a,
    const U &b,
    const char *str_a,
    const char *str_b,
    const char *file_name,
    int position
    ) {
        if (a >= b) return CompareMsg();
        return CompareMsg(str_a, ">=", str_b, a, b, file_name, position);
    }

#define EXPECT(a, b, comp) {                                     \
    CompareMsg CompMsg = comp(a, b, #a, #b, __FILE__, __LINE__); \
    if (CompMsg) {                                               \
        if (TestUnit::GetInstance()->getTestInfo()) {            \
            TestUnit::GetInstance()->getTestInfo()->run_flag = false; \
        }                                                        \
        cout << CompMsg.msg() << endl;                           \
    }                                                            \
}

#define EXPECT_EQ(a, b) EXPECT(a, b, CompareEQ)
#define EXPECT_NE(a, b) EXPECT(a, b, CompareNE)
#define EXPECT_LT(a, b) EXPECT(a, b, CompareLT)
#define EXPECT_LE(a, b) EXPECT(a, b, CompareLE)
#define EXPECT_GT(a, b) EXPECT(a, b, CompareGT) 
#define EXPECT_GE(a, b) EXPECT(a, b, CompareGE)

#define KTEST_CLASS_NAME(a, b) Eric_##a##_##b##_TestName 

//继承测试用例基类，可以借用基类指针，访问不同的测试用例
#define TEST(test_suit_name, test_name)                                       \
class KTEST_CLASS_NAME(test_suit_name, test_name)                             \
: public TestBase{                                                            \
public:                                                                       \
    KTEST_CLASS_NAME(test_suit_name, test_name)() {}                          \
    virtual void TestBody() override;                                         \
    static const TestInfo *test_info;                                         \
};                                                                            \
                                                                              \
const TestInfo *KTEST_CLASS_NAME(test_suit_name, test_name)::test_info =      \
    MakeAndRegisterTestInfo (                                                 \
        #test_suit_name,                                                      \
        #test_name,                                                           \
        new TestFactoryImpl<KTEST_CLASS_NAME(test_suit_name, test_name)>()    \
    );                                                                        \
                                                                              \
void KTEST_CLASS_NAME(test_suit_name, test_name)::TestBody()                   


int RUN_ALL_TESTS() {
    for (auto t : *(TestUnit::GetInstance())) {
        t->run();
    }
    return 0;
}
#endif
