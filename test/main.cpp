#include <LogProject/Log.h>
#include <LogProject/LogPlatform.h>

#include "Variant.h"

#include <vector>
#include <unordered_set>

int MAIN()
{
	Log::Init(1024, Log::Enum::eMode_Print | Log::Enum::eMode_Save, Log::Enum::eLevel_Type);

	LOGINFO() << "Hello World!";

	{
		// Base Type Test
		wtr::Variant<int, float, double> var;

		var.Set(1.0f);
	
		LOGINFO() << "Float Check : " << var.Is<float>();
		LOGINFO() << "Float Value : " << var.Get<float>();
		LOGINFO() << "Float Index : " << var.GetIndex();
	
		var.Set(2.0);	
	
		LOGINFO() << "Double Check : " << var.Is<double>();
		LOGINFO() << "Double Value : " << var.Get<double>();
		LOGINFO() << "Double Index : " << var.GetIndex();
	}

	{
		// Copy Test;
		wtr::Variant<int, float, double> var;

		var.Set(100);

		wtr::Variant<int, float, double> var1 = var;

		LOGINFO() << "Copy Check : " << var1.Is<int>();
		LOGINFO() << "Copy Value : " << var1.Get<int>();

	}

	{
		// Destructor Test
		class Object
		{
			public:
				Object()
				{
					LOGINFO() << "Object Constructor!";
				}
				~Object()
				{
					LOGINFO() << "Object Destructor!";
				}
		};
		
		wtr::Variant<int, Object> var2;

		var2.Set(Object());
		LOGINFO() << "Object Check : " << var2.Is<Object>();
	
		var2.Set(1);
		LOGINFO() << "Int Check: " << var2.Is<int>();
	}

	{
		// STL Container Test
		wtr::Variant<std::vector<int>, std::vector<float>, std::vector<double>> var3;
		var3.Set(std::vector<int>{ 1, 2, 3, 4, 5 });
		LOGINFO() << "Vector Check : " << var3.Is<std::vector<int>>();
		LOGINFO() << "Vector Value of Index 0 : " << var3.Get<std::vector<int>>()[0];
	}

	{
		struct Object
		{
			std::shared_ptr<Object> spChild;
			int Value;

			Object()
				: spChild(nullptr)
				, Value(0)
			{}

			Object(const Object& _other)
				: spChild(_other.spChild)
				, Value(_other.Value)
			{}
		};

		// Deep Copy Test
		wtr::Variant<int, std::string, Object> var1;
		wtr::Variant<int, std::string, Object> var2;
		wtr::Variant<int, std::string, Object> var3;

		var1.Set<std::string>("Hello World!");

		var2 = var1;

		LOGINFO() << "Copy String : " << var2.Get<std::string>();

		var3 = std::move(var1);

		LOGINFO() << "Move String : " << var2.Get<std::string>();
	}

	// var.Set(true);
	// LOGINFO() << "Index : " << var.GetIndex();

	{
		// Hash Test
		wtr::Variant<int, float, double> var4, var5, var6, var7;
		var4.Set(1.0f);
		var5.Set(1.2f);
		var6.Set(0.0f);
		var7.Set(2.0f);

		LOGINFO() << "Hash Value : " << var4.GetHash();
		LOGINFO() << "Hash Value : " << var5.GetHash();
		LOGINFO() << "Hash Value : " << var6.GetHash();
		LOGINFO() << "Hash Value : " << var7.GetHash();

		std::unordered_set<wtr::Variant<int, float, double>> set;

		set.insert(var4);
		set.insert(var5);
		set.insert(var6);
		set.insert(var7);

		for (auto& iter : set)
		{
			LOGINFO() << "Value : " << iter.Get<float>() << " | Hash Value : " << iter.GetHash();
		}
	}

	system("pause");

	return 0;
}