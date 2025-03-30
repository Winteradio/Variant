#include <LogProject/Log.h>
#include <LogProject/LogPlatform.h>

#include "Variant.h"

#include <vector>

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

	// var.Set(true);
	// LOGINFO() << "Index : " << var.GetIndex();

	system("pause");

	return 0;
}