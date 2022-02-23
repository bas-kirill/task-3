#include "pch.h"
#include "CppUnitTest.h"
#include "../task_2_sem_3/task_2_sem_3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {
            template <> static std::wstring ToString(const vec_2& q) {
                wstringstream s;
                s.precision(4);
				s << "\n";
				for (auto iter = q.begin(); iter != q.end(); iter++) {
					for (auto it = iter->begin(); it != iter->end(); it++) {
						s << *it << " ";
					}
					s <<"\n" ;
				}
                return s.str();
            }
        }
    }
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace created2
{
	TEST_CLASS(created2)
	{
	public:
		
		TEST_METHOD(d2_integer)
		{
			{
				stringstream ss;
				ss << "1 2 3 2 5 4 6 3 7";
				vec_2 t_actual = create_d2(ss,3,3); //что делать с сайзом???

				vec_2 t_exprcted = {
									{1,2,3},
									{2,5,4},
									{6,3,8}
				};
				Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
				Assert::AreEqual(t_actual, t_exprcted);
			}
		}
		TEST_METHOD(d2_doubble)
		{
			{
				stringstream ss;
				ss << "1.2 2 -3.45 2 5 4 6 3.765 8";
				vec_2 t_actual = create_d2(ss, 3, 3);

				vec_2 t_exprcted = {
									{1.2,2,-3.45},
									{2,5,4},
									{6,3.765,8}
				};
				Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
				Assert::AreEqual(t_actual, t_exprcted);
			}
		}
		TEST_METHOD(d2_emptyy)
		{
			{
				stringstream ss;
				ss << "";
				ss.peek();
				vec_2 t_actual = create_d2(ss, 0, 0);

				vec_2 t_exprcted = {};
				Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
				Assert::AreEqual(t_actual, t_exprcted);
			}
		}
	};
}
