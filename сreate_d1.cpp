#include "pch.h"
#include "CppUnitTest.h"
#include "../task_2_sem_3/task_2_sem_3.cpp"
namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {
            template <> static std::wstring ToString(const vec& q) {
                wstringstream s;
                s.precision(4);       
                for (auto i = q.begin(); i != q.end(); i++) {
                    s << *i << ' ';
                }
                return s.str();
            }
        }
    }
}


//что эта запись означает и зачем это нужно вообще?????

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace сreated1
{
	TEST_CLASS(сreated1)
	{
	public:
		
		TEST_METHOD(сreated_integer)
		{
            stringstream ss;
            ss << "-5 0 -2 4 6";     
            vec t_actual = create_d1(ss);
           
			vec t_exprcted = { -5,0,-2,4 };
            
            
            Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
        TEST_METHOD(сreated_doubble)
        {
            stringstream ss;
            ss << "-5.4 0.2 -2 4";
            vec t_actual = create_d1(ss);
            vec t_exprcted = { -5.4,0.2,-2,4 };
            Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
            Assert::AreEqual(t_actual, t_exprcted);
        }
        TEST_METHOD(сreated_emptyy)
        {
            stringstream ss;
            ss << "";               
            ss.peek();
            vec t_exprcted = {};
            Assert::AreEqual(create_d1(ss), t_exprcted);
        }
	};
}

