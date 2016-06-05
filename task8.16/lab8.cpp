#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

namespace ax {

	class Base
	{
	public:
		Base(int value) : value_(value)
		{
		}

		virtual void show() = 0;

		virtual~Base()
		{
		}

	protected:
		int value_;
	};

	class A : public Base
	{
	public:
		A(int value) : Base(value)
		{
		}

		void show()
		{
			std::cout << "class A : " << value_ << std::endl;
		}

		~A()
		{
		}
	};

	class B : public Base
	{
	public:
		B(int value) : Base(value)
		{
		}

		void show()
		{
			std::cout << "class B : " << value_ << std::endl;
		}

		~B()
		{
		}
	};

	class C : public Base
	{
	public:
		C(int value) : Base(value)
		{
		}

		void show()
		{
			std::cout << "class C : " << value_ << std::endl;
		}

		~C()
		{
		}
	};


	
};

namespace fn {

	class FunctorBase
	{
	public:
		FunctorBase()
		{
		}

		virtual void operator()(const std::vector<std::string> & args) = 0;

		~FunctorBase()
		{
			for (std::list<ax::Base*>::iterator it = outptr->begin(); it != outptr->end(); ++it)
			{
				delete (*it);
			}
		}
	protected:
		static std::list<ax::Base*>  * outptr; // static vector of object
	};

	class FBaseCreate : public FunctorBase
	{
	public:
		FBaseCreate()
		{
		}

		void operator()(const std::vector<std::string> & args)
		{
			std::string className = args[0];
			int value = std::stoi(args[1]);

			factoryMap["A"] = new ax::A(value);
			factoryMap["B"] = new ax::B(value);
			factoryMap["C"] = new ax::C(value);

			if (factoryMap[className] != nullptr) {
				outptr->push_back(factoryMap[className]);
			}
		}

		~FBaseCreate()
		{
			FunctorBase::~FunctorBase();
		}
	private:
		std::map<std::string, ax::Base*> factoryMap;
	};


	class FBaseShow : public FunctorBase
	{
	public:
		FBaseShow()
		{
		}

		void operator()(const std::vector<std::string> & args)
		{
			for (std::list<ax::Base*>::iterator it = outptr->begin(); it != outptr->end(); ++it )
			{
				(*it)->show();
			}
		}

		~FBaseShow()
		{
			FunctorBase::~FunctorBase();
		}
	};
}


std::map<std::string, fn::FunctorBase*> cmdMap;

std::list<ax::Base*> * fn::FunctorBase::outptr = new std::list<ax::Base*>();

int main()
{
	cmdMap["create"] = new fn::FBaseCreate;
	cmdMap["show"] = new fn::FBaseShow;

	std::vector<std::string> arguments;
	std::string command;

	std::size_t nCount = 0;
	std::cin >> nCount;
	
	std::string strBuffer;

	for (std::size_t i = 0; i < nCount; ++i)
	{
		std::cin >> command;
		arguments.clear();

		if (command == "create") {
			std::cin >> strBuffer;
			arguments.push_back(strBuffer);
			std::cin >> strBuffer;
			arguments.push_back(strBuffer);
		}

		if (cmdMap[command] != nullptr) {
			cmdMap[command]->operator()(arguments);
		}
	}

	for (std::map<std::string, fn::FunctorBase*>::iterator it = cmdMap.begin(); it != cmdMap.end(); ++it)
	{
		delete (*it);
	}

	system("pause");
	return 0;
}
