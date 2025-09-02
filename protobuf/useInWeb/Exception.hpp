#include <string>

class ContactException{
	public:
		ContactException(const std::string &message = "Npo Problem"):
		_message(message){}
		
		std::string what()const{
			return _message;
		}
	private:
		std::string _message;
};

