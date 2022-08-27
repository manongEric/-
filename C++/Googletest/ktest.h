/*************************************************************************
	> File Name: ktest.h
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Aug 2022 11:24:24 PM CST
 ************************************************************************/

#ifndef _KTEST_H
#define _KTEST_H

class TestBase;
class TestFactoryBase {
public:
    virtual TestBase *getObject() = 0; // 生成测试用例的对象
};

template<class CLASS_T> //运用模板，每个类型的测试用例只需要一个工厂
class TestFactoryImpl {
public:
    TestBase *getObject override {
        return new CLASS_T();
    }
    void destory(TestBase *test_unit)  {
        assert(dynamic_cast<CLASS_T *>(test_unit) != nullptr);//测试用例类型和classT一样才能销毁
        delete test_unit;
        return;
    }
};

class TestBase {
public:
    virtual void TestBody() = 0;//所有测试用例执行的过程
};

class TestInfo{//记录测试用例的信息
public:
    TestInfo(
        const char* test_suit_name,
        const char* test_name, 
        TestFactoryBase* factory
    ) : {}
    
    void run() {
        TestBase* test_unit = factory->getObject();
        test_unit->TestBody();
        factory->destory(test_unit);
        return;
        }

private:
    const char* test_suit_name;
    const char* test_name;
    TestFactoryBase* factory;
};
class TestUnit {
public:
    static TestUnit* GetInstance();

    void AddTestInfo(TestInfo* test_info) {
        test_info_arr.push_back(test_info);
        return;
    }

    vector<TestInfo *>::iterator begin() {return test_info_arr.begin();}
    vector<TestInfo *>::iterator end() {return test_info_arr.end();}
private:
    vector<testInfo *> test_info_arr;
    TestUnit(){}
    TestUnit(const TestUnit &) = delete;

    static std::mutex m_mutex;
    static TestUnit *singel;
};

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


#define KTEST_CLASS_NAME(a, b) Eric_##a##_##b##_TestName 

//继承测试用例基类，可以借用基类指针，访问不同的测试用例
#define TEST(test_suit_name, test_name)                                       \
class KTEST_CLASS_NAME(test_suit_name, test_name)                             \
: public TestBase{                                                            \
public:                                                                       \
    KTEST_CLASS_NAME(test_suit_name, test_name)() {}                          \
    virtual void TestBase() override;                                         \
    static const TestInfo *test_info;                                         \
};                                                                            \
                                                                              \
const TestInfo *KTEST_CLASS_NAME(test_suit_name, test_name)::test_info =      \
    MakeAndRegisterTestInfo (                                                 \
        #test_suit_name,                                                      \
        #test_name,                                                           \
        new TestFactoryImpl<KTEST_CLASS_NAME(test_suit_name, test_name)>()    \
    );                                                                        \
};                                                                            \
void KTEST_CLASS_NAME(test_suit_name, test_name)::TEST_Base()                 //头部信息


void RUN_ALL_TEST() {
    for (auto t : *(TestUnit::GetInstance())) {
        t->run();
    }
    return ;
}
#endif
