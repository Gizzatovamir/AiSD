#include <iostream>
#include <cctype>
#include <string>
#include <regex>
int srch_sub_list(std::string str);
class List{
	public:
	char El;
	List *next;
	List *Sub_list;
	List(std::string str){					//constructor
		if(str != ""){
			if(str[0] =='('){
				str.erase(0,1);
				str.erase(str.length()-1,1);
			}
			El = str[0];
			std::cout << El << std::endl;
			if(str[1]=='('){
				//str.erase(0,1);
				std::string sub_str = str.substr(1,srch_sub_list(str));
				//std::cout<<str.substr(1,srch_sub_list(str))<<" "<< srch_sub_list(str) <<std::endl;
				Sub_list = new List(sub_str);
				str.erase(1,sub_str.length());
			}
			else{
				Sub_list = nullptr;
			}
			str.erase(0,1);
			//if(str!="")
				next = new List(str);
		}
		else{
			El = '\0';
			next = nullptr;
			Sub_list = nullptr;
		}
		
	}
	~List(){						//destructor
		delete next;
		delete Sub_list;	
	}
	List(char s,List *sub_str_list){			//constructor in_list
		El = s;
		Sub_list = sub_str_list;
	}
	int count(){						//counting the amount of elemnts in list
		int res=0;
		List *ptr= next;
		while(ptr !=nullptr){
			if(ptr!=nullptr){
				res++;
			}
			ptr=ptr->next;
		}
		return res;
	}

	void print_list(){					//printing the list in the terminal
		if(Sub_list != nullptr){
			std::cout<< "(";
                        Sub_list->print_list();
                        std::cout<<")";
 	                std::cout <<  El;
                }
		else{
			std::cout <<  El;
		}

		if(next != nullptr){
			next->print_list();
		}
	}
};
List *rev(List *head) {						//function that reversing the list
	List *ptr1 = head;
	List *ptr2;
	List *ptr_last;
	List *rev_list;
	while (ptr1->next != nullptr) {
		if(ptr1->Sub_list != nullptr){
			ptr1->Sub_list=rev(ptr1->Sub_list);		
		}
		rev_list = ptr1;
		ptr1 = ptr1->next;

	}
	ptr1 = head->next;
	head->next = nullptr;
	ptr2 = head;
	head = ptr1;
	ptr1 = ptr1->next;
	while (ptr1!= nullptr) {
		head->next = ptr2;
		ptr2 = head;
		std::cout << "head " << ptr2->El <<std::endl;
		head = ptr1;
		ptr1 = ptr1->next;
	}
	return rev_list;
}

int srch_sub_list(std::string str){				//searching the in_list
	int i = 0 ,open_br=0,k,close_br = 0;
		do{
			if(str[i] == ')'){
				k = i;	
			}
			i++;
		}
	while(i<str.length());
		return k;
}

int br_check(std::string str){					//cheking brackets for valuability
	int i=0,open_br=0,close_br=0;
	for(i;i<str.length();i++){
                        if(str[i]=='('){
                                open_br++;
                        }
                        if(str[i] == ')'){
                                close_br++;
                       }
	}
        if(open_br==close_br)
                return i;
        else
                return -1;
	
}

bool is_valuable(std::string str){						//checking the text for valuability
	if(br_check(str)>0){
		for(int i=0;i<str.length()-1;i++){
			if(str[i]=='(' && str[i+1]=='('){
				return false;
			}
			if(str[i] == ')' && str[i+1] == '('){
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
	
}	

int main(){
	std::string str;
	std::cout << "Введите иерархичесий список" << std::endl;
	getline(std::cin,str);						//geting the text
	str=std::regex_replace(str,std::regex(" "),"");			//deleting all spaces
//	std::cout << str << std::endl;
	if(is_valuable(str)){
		List *lst = new List(str);
		lst->print_list();					//creating list
		std::cout<<std::endl;
		lst->print_list(); 
		List *rev_list = rev(lst);				//reversing the list
		std::cout << "(";
		rev_list->print_list();
		std::cout<<")"<<std::endl;
		delete(rev_list);
		delete(lst);

	}
	else{
		std::cout << "text is not correct" << std::endl;
		return 0;
	}
	return 0;
}
