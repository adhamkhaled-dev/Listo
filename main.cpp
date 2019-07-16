#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main(){
    vector <int> list {};
    char selection {};
    do{
        cout<<"\nP - Print numbers"<<"\nA - Add a number"<<"\nM - Display mean of the numbers";
        cout<<"\nC - Clear the list"<<"\nF - Search for an item in the list"<<"\nD - Display the standard deviation of the integers";
        cout<<"\nS - Display the smallest number"<<"\nL - Display the largest number"<<"\nQ - Quit"<<endl;
        cout<<"Enter your choice: ";
        cin>>selection;
        switch (selection){
            case 'p': //Print all the integers
            case 'P':
                if (list.size()==0)
                    cout<<"[] - the list is empty"<<endl;
                else{
                    cout<<"[";
                    for (auto item: list)
                        cout<<" "<<item;
                    cout<<" ]";
                }break;
            case 'a':
            case 'A':
            {
                int add {};
                cout<<"Enter an integer to be added to the list: ";
                cin>>add;
                list.push_back(add);
                cout<<add<<" added!";
                break;
            }
            case 'd': // Standard deviation
            case 'D':
                if (list.size() == 0)
                    cout<<"Unable to calculate the standard deviation - no data";
                else{
                    int sum {};
                    for (auto element: list)
                        sum += element;
                    double mean {static_cast<double>(sum)/list.size()};
                    double sumdist {};
                    for (auto element: list){
                        sumdist += pow(abs(element-mean),2);
                        }
                    double sd {sqrt(sumdist/list.size())};
                    
                    cout<<"The standard deviation of the integers is "<<std::setprecision(3)<<sd<<endl;
                }
                break;
            case 'm': // Mean of the integers
            case 'M':
                if (list.size() == 0)
                    cout<<"Unable to calculate the mean - no data";
                else{
                    int sum {};
                    for (auto element: list)
                        sum += element;
                    cout<<"The mean of your list is "<<static_cast<double>(sum)/list.size()<<endl;
                }
                break;
            case 's': //Smallest integer
            case 'S':
                if (list.size()==0)
                    cout<<"Unable to determine the smallest number - list is empty"<<endl;
                else{
                    int min {list[0]};
                    for(auto element: list){
                        if (min>element){
                            min = element;
                            }
                        }
                    cout<<"The smallest number in the list is "<<min<<endl;
                }break;
            case 'l': //Largest integer
            case 'L':
                if (list.size()==0)
                    cout<<"Unable to determine the largest number - list is empty"<<endl;
                else{
                    int max {list[0]};
                    for (auto element: list){
                        if (max<element)
                            max=element;
                        }
                    cout<<"The largest number in the list is "<<max<<endl;
                }break;
            case 'c': //Clear the list
            case 'C':
            	list.clear();
            	cout<<"The list has been cleared"<<endl;
            	break;
            case 'f': //Find how many times is the integer found in the list
            case 'F':{
            	int search {};
            	unsigned count {};
            	cout<<"Enter the item you want to search in the list: ";
            	cin>>search;
            	for (auto element: list){
            		if (element == search)
            			count++;
            		}
            	if (count==0)
            		cout<<"Item not found. However, you can add it by selecting 'A' in the choices."<<endl;
            	else if (count == 1)
            		cout<<"The integer: "<<search<<" was found 1 time in the list."<<endl;
            	else
            		cout<<"The integer: "<<search<<" was found "<<count<<" times in the list."<<endl;
            	break;
            }
            case 'q': //Quit the program
            case 'Q':
                cout<<"Goodbye!";
                break;
            default: cout<<"\nPlease write a valid entery.";
            }
    	cout<<endl;
    }while(selection!='Q' && selection != 'q');
    
    
    cout<<endl;
    return 0;
    
    }
    