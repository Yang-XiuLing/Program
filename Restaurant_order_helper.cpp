//
// Created by PC on 2026/7/19.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
namespace restaurant {
//展示菜单
    void menu(int sizes , const string names[] , const float price[]) {
        cout<<"This is our restaurant's menu (choose 0 can return)"<<endl<<"=========================="<<endl;
        cout<<"//  size  /"<<"/  name    /"<<"/    price  //"<<endl;
        //循环输出菜单
        for (int i = 0 ; i < sizes ; i++) {
            cout<<"  "<<i + 1<<",  "<<"  "<<names[i]<<"  "<<"  "<<price[i]<<'$'<<"  "<<endl;
        }
        cout<<"=========================="<<endl;
        std::this_thread::sleep_for(300ms);
    }

//总计金额
    float total_price(const float price[] , int sizes , const string names[] ) {
        float count[10] = {};
        float count_1[10] = {};
        string count_2[10] = {};
        int choice;
        float quantity;
        int n = 0;
        float total = 0;
        star:cout<<"inputting size to choose food (choose 0 to summarize)"<<endl;
        cout<<"[ most than 10 ]"<<endl;
        cin>>choice;
        if (cin.fail()) {cin.clear();cin.ignore(2);cout<<"mistake"<<endl;goto star;}
    //判断点餐数量，计算总金额
        if (choice >= 0 && choice <= sizes && n < 10) {
            while (choice >= 0) {
                //判断操作
                if (choice > 0) {
                    cout<<"choose the quantity"<<endl;
                    cin>>quantity;
                    cout<<"have added"<<endl;
                    count[n] = quantity;
                    count_1[n] = price[choice];
                    count_2[n] = names[choice];
                    //此处应该添加菜名
                    total = total + price[choice] * quantity;
                    cout<<"inputting size to choose other food (choose 0 to summarize)"<<endl;
                    cout<<"most than 10 "<<endl;
                    cin>>choice;
                    n++;
                }
                if (choice == 0) {std::this_thread::sleep_for(300ms);break;}
            }
            for ( int j = 0 ; j < 10 ; j++ ) {
                if (count[j] != 0) {
                    cout<<count_2[j]<<":  "<<count_1[j]<<'$'<<"  *  "<<count[j]<<endl;
                    std::this_thread::sleep_for(100ms);
                }
                if (count[j] == 0)
                    break;
            }
            cout<<"=========================="<<endl;
            std::this_thread::sleep_for(300ms);
            cout<<"total"<<endl<<total<<'$'<<endl;
        }
        if (n == 10) {cout<<"overloading"<<endl;std::this_thread::sleep_for(300ms);}
        else {cout<<"MISTAKE,restate to choose"<<endl;std::this_thread::sleep_for(300ms);goto star;}

        return total;
    }
}

//创建类来实现定义菜单，价格等等
class Rest {
public:
    string food_name[100] = {
    "Lanzhou Beef Noodles","Shanxi Knife-Cut Noodles",
    "Shaanxi Oil-Spilled Noodles (Oil-Splash Noodles)","Biangbiang Noodles",
    "Qishan Noodles with Minced Pork (Saozi Noodles)","Henan Stewed Noodles (Huimian)",
    "Beijing Noodles with Fried Sauce (Zhajiangmian)",
    "Wuhan Hot-Dry Noodles (Re Gan Mian)","Sichuan Dan Dan Noodles",
    "Chongqing Small Noodles (Xiao Mian)","Yibin Burning Noodles (Ranmian)",
    "Yanji Cold Noodles","Zhenjiang Pot Cover Noodles",
    "Hangzhou Pian Er Chuan Noodles","Kunshan Aozao Noodles",
    "Xiamen Satay Noodles","Guangzhou Bamboo Noodles","Hong Kong Cart Noodles",
    "Chaozhou Fish Noodles","Guiyang Intestine and Blood Curd Noodles",
    "Zunyi Tofu Flower Noodles","Xinjiang Pulled Noodles (Lagman)",
    "Japanese Ramen","Korean Black Bean Noodles (Jajangmyeon)",
    "Spaghetti (or Pasta)","Plain Noodles in Clear Soup (Yangchunmian)",
    "Scallion Oil Noodles","Cold Tossed Noodles",
    "Fried Noodles","Braised Noodles (Menmian)","Boiled Noodles with Toppings (Laomian)",
    "Noodles with Thick Gravy (Dalu Mian)",
    "Noodles with Sesame Paste","Chilled Noodles (Guoshuimian)","Dragon Beard Noodles",
    "Dried Hanging Noodles","Hand-Rolled Noodles","Udon Noodles",
    "Hele Noodles (Pressed Noodles)","Alkaline Noodles",
    "Wonton Noodles","Old Friend Rice Noodles (Laoyou Fen)",
    "Liuzhou River Snail Rice Noodles (Luosifen)","Mutton Rice Noodles",
    "Duck Blood and Vermicelli Soup","Hot and Sour Rice Noodles (Suān Là Fěn)",
    "Rice Noodles (Mixian)"
    };
    float food_price[100] = {
        14.00 ,13.00 ,14.00 ,13.00 ,12.00 ,
        13.00 ,11.00 ,10.00 ,11.00 ,10.00 ,
        10.00 ,12.00 ,12.00 ,13.00 ,13.00 ,
        14.00 ,12.00 ,10.00 ,13.00 ,13.00 ,
        12.00 ,12.00 ,14.00 ,12.00 ,15.00 ,
        8.00 ,9.00 ,9.00 ,11.00 ,12.00 ,
        10.00 ,11.00 ,10.00 ,9.00 ,12.00 ,
        8.00 ,10.00 ,12.00 ,11.00 ,9.00 ,
        13.00 ,12.00 ,13.00 ,14.00 ,12.00 ,
        10.00 ,11.00
    };
/*    int food_size[100] = {1,2,3,4,5,6,7,8,9,10,
                          11,12,13,14,15,16,17,
                          18,19,20,21,22,23,24,
                          25,26,27,28,29,30,31,32,
                          33,34,35,36,37,38,39,40,
                          41,42,43,44,45,46,47,48,
                          49,50,51,52,53,54,55,56,
                          57,58,59,60,61,62,63,64,
                          65,66,67,68,69,70,71,72,
                          73,74,75,76,77,78,79,80,
                          81,82,83,84,85,86,87,88,
                          89,90,91,92,93,94,95,96,
                          97,98,99,100
    };
*/
    int food_sizes = 47;
};

//编写主程序
int main () {
    Rest R;
    restaurant::menu(R.food_sizes,R.food_name,R.food_price) ;
    restaurant::total_price(R.food_price,R.food_sizes,R.food_name);
    std::this_thread::sleep_for(27s);
    cout<<"returning...";
    std::this_thread::sleep_for(3s);
    return 0;
}