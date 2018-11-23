#include <iostream>
#include <regex>
#include <string>
#include <cstring>
#include <ctype.h>
#include <fstream>
#define READ
class q_El{
	public:
	char El;
	q_El *next;
	q_El(char el){
		El = el;
		next = nullptr;
	}
	~q_El(){
//		delete next;
	}
	
};

class q_list{
	public:
	q_El *head = nullptr;
	q_El *tail = nullptr;
	q_list(std::string str){
		q_El *cur=nullptr;
		q_El *ptr=nullptr;
		for(int i=0;i<str.length();i++){
			cur = new q_El(str[i]);
			if(ptr != nullptr)
				ptr->next = cur;
			if(i==0)
				head = cur;
			if(i == str.length()-1)
				tail = cur;
			ptr=cur;
		
		}	
	}	
        ~q_list(){
//		delete head;
//		if(head != tail){
//			delete tail;
//		}	
	}
        void push(q_list *lst,char El){
                q_El *ptr = new q_El(El);						//pushing an elemnt to the end of the queue
                ptr->next = head;
                head = ptr;
        }
        char pop(){
        	        char cur_El = tail->El;
          	    	q_El *cur = prev_tail(head);
             	  	if(cur == nullptr){
				delete head;
				head = nullptr;
				tail = nullptr;						//the function is deleting the last element and returning it
				return cur_El;						
               		}
			else{
				delete cur->next;
				cur->next = nullptr;
       		 	        tail = cur;
       	 		        return cur_El;
			}
        }
        bool isEmpty(){
                if(head == nullptr){
                        return true;
                }
                else{
                        return false;
                }
        }
        int count(){
                int i=0;
                q_El *ptr = head;
		if(isEmpty() == true){
			return i;
		}
                while(ptr->next != nullptr ){
			i++;
                       // std::cout << ptr->El << " ";
			ptr = ptr->next;
                }
		//std::cout<<ptr->El << std::endl;
                return i+1;

        }
        q_El *prev_tail(q_El *lst){
                q_El *ptr = lst;
		if(ptr->next == nullptr){
			return ptr;						//searching element that is previous to the last element
		}
                while(ptr->next->next != nullptr){
                        ptr = ptr->next;
                }
                return ptr;
        }
};

void digit_srch(q_list *lst){
	char *text = (char*)calloc(2000,sizeof(char));
	char *digits = (char*)calloc(2000,sizeof(char));
	char *str = (char*)calloc(4000,sizeof(char));
	int i=0,j=0,count;
	char el;
#ifdef READ
	std::ofstream F1;
#endif
	count = lst->count();
	while(count > 0){
		el = lst->pop();
		if(isdigit(el) > 0){
			digits[j] = el;									// poping all digits and write them into line named digits
			j++;
			std::cout <<"текущая строка для цифр - " << digits << std::endl;
		}
		else{
			text[i] = el;									//poping all other elements and write them into line named text
			i++;
	                std::cout <<"текущая строка для символов - " << text << std::endl;
		}	
		count--;
	}
	i=0;
	for(int k = strlen(text)-1;k>=0;k--){							//making the final line by reversing text, digits lines and write them into str
		str[i] = text[k];
	        i++;	
	}
	for(int l = strlen(digits)-1;l>=0;l--){
		str[i] = digits[l];
		i++;
	}
#ifdef READ
	F1.open("2.txt",std::ios_base::app);
	F1 << str << std::endl<<std::endl;
	F1.close();
#endif
	std::cout<< str << std::endl;
		free(text);
        	free(digits);
		free(str);
}


int main(){
        std::string text;
#ifndef READ
	std::getline(std::cin,text);
#endif
#ifdef READ
	std::fstream F;
	F.open("1.txt",std::ios::in);
	while(!F.eof()) {
			std::getline(F,text);
			text=std::regex_replace(text,std::regex("\n"),"");
			q_list lst(text);
			digit_srch(&lst);
			text.clear();										//doing the algorithm to each line that is gotten
	}
	F.close();
#endif
        q_list lst(text);
	digit_srch(&lst);
}


