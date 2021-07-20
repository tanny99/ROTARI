#include<bits/stdc++.h>
#include<sstream>
using namespace std;
class User
{
    string name;
    double balance;
    int id;
    string address;
public:
    void setId(int a){
        id = a;
    }
    void setName(string a){
        name = a;
    }
    void setAddress(string a){
        address = a;
    }
    void setBalance(double a){
        balance = a;
    }

    string getUserName()
    {
        return name;
    }
    string getUserAddress()
    {
        return address;
    }
    int getUserId()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
    void updateBalance(double totalAmount)
    {
        balance-=totalAmount;
    }
};
class Product
{
    int qty;
    string name;
    string description;
    double price;
public:
    void setProductName(string name)
    {
        this->name=name;
    }
    void setProDesc(string description)
    {
        this->description=description;
    }
    void setPrice(double price)
    {
        this->price=price;
    }
    string getProductName()
    {
        return name;
    }
    string getProductDesc()
    {
        return description;
    }
    double getProductPrice()
    {
        return price;
    }
    void setQuantity(int x)
    {
        qty=x;
    }
    int checkQty()
    {
        return qty;
    }
    void updateQty(int x)
    {
        qty-=x;
    }
};
class Cart
{
    double bill=0;
public:
    void addProduct(double price,int count)
    {
        bill+=price*count;
    }
    void removeProduct(double price,int count)
    {
        bill-=price*count;
    }
    double getBill()
    {
        return bill;
    }
};
unsigned int HashFunction(string input)
{
    unsigned int Magic = 19103048;
    unsigned int Hash;
    for(int i=0; i<input.length();i++)
    {
        Hash = Hash^(input[i]);
        Hash = Hash * Magic;
    }
    return Hash;
}
string ToHex(unsigned int input)
{
    string HexHash;
    stringstream hexstream;
    hexstream << hex << input;
    HexHash = hexstream.str();
    std::transform(HexHash.begin(), HexHash.end(), HexHash.begin(), ::toupper);
    return HexHash;
}
int main()
{
    ofstream fout1,fout2;
    ifstream fin1,fin2;
    cout<<"Welcome"<<endl;
    cout<<"Press 0 to Login"<<endl;
    cout<<"Press 1 to SignUp"<<endl;
    int option;cin>>option;
    if(option){
        //sign up
      string name,address,wallet,phoneNo;
        cout<<"Enter your Name"<<endl;
        cin>>name;
        cout<<"Enter your Address"<<endl;
        cin>>address;
        cout<<"Enter your Wallet Balance"<<endl;
        cin>>wallet;
        cout<<"Enter your phone number"<<endl;
        cin>>phoneNo;
        cout<<"Enter your password"<<endl;
        string pass;
        cin>>pass;
       
        cout<<endl;
        // int l=pass.size();
        // int qq=int(pass[0]);
        // for(int i=0;i<pass.size();i++){
        //     cout<<pass[i]<<endl;
        // }
        // for(int i=0;i<pass.size();i++){
        //     pass[i]=pass[i]-int(pass[i])+ (int(pass[0])+ 2*i)%128;
        //     cout<<pass[i];
        // }
        // cout<<endl;
        //    for(int i=0;i<pass.size();i++){
        //     pass[i]=pass[i]+int(pass[i])- (int(pass[0])+ 2*i)%128;
        //     cout<<pass[i];
        // }
        // string line;
        // ifstream fin2;
        // fin2.open("passwords.txt");
        // while (std::getline(fin2, line)){
        //     if(//check)
        // }
        string encrypted = ToHex(HashFunction(pass));
        fout1.open("phone.txt",std::ios_base::app);
        fout2.open("passwords.txt",std::ios_base::app);
        fout1<<phoneNo<<endl;
        cout<<"your added pass- "<<encrypted;
        fout2<<encrypted<<endl;
        fin1.open("users.txt");
        int n=0;string line;
        while (std::getline(fin1, line))
            ++n;
        fin1.close();
        fout1.close();
        fout2.close();
        fout1.open("users.txt",std::ios_base::app);
        fout1<<name<<" "<<wallet<<" "<<n+1<<" "<<address<<endl;
        fout1.close();
    

    }
    else{
        //login
        string phoneNo;
        cout<<"Enter your phone number"<<endl;
        cin>>phoneNo;
        cout<<"Enter your password"<<endl;
        string pass;
        cin>>pass;
        string encrypted = ToHex(HashFunction(pass));
        cout<<"your added pass- "<<encrypted;
        //check login
        //
        string line2;
        fin1.open("phone.txt");
        int n1=0,flag1=0 ,flag=0,qqw=0;
        while (std::getline(fin1, line2)){
            ++n1;
            if(line2==phoneNo){
                // cout<<endl<<"@@"<<n1;
                 flag=1;
                 qqw=n1;
            }
        }
            
        fin1.close();
        if(flag==0){
            cout<<endl<<"NO USER EXIST!"<<endl;
        }
        else{
            string line3;
        fin1.open("passwords.txt");
        int n2=0;
        while (std::getline(fin1, line3)){
            ++n2;
            if(line3==encrypted){
                // cout<<endl<<"$$"<<n2;
                 flag1=1;
            }
        }
            
        fin1.close();
        
        }
        if(flag1==1){
            cout<<endl<<"Welcome to ROTARI!!"<<endl;
             fin1.open("users.txt");
        int n3=0;string line;
        while (std::getline(fin1, line))
            ++n3;
        fin1.close();
        fin1.open("users.txt");
        // cout<<endl<<n3;  
        User user[n3];
        string data1,data4;
        double data2;
        int data3;
        for (int i=0;i<n3;i++){
            fin1>>data1;
            fin1>>data2;
            fin1>>data3;
            fin1>>data4;
            user[i].setName(data1);
            user[i].setBalance(data2);
            user[i].setId(data3);
            user[i].setAddress(data4);    
           
        }

        

        fin1.close();


        //products

         fin1.open("products.txt");
        int n4=0;
        while (std::getline(fin1, line))
            ++n4;
        fin1.close();
        fin1.open("products.txt");
        // cout<<endl<<n4;
        Product products[n4];
        for (int i=0;i<n4;i++){
            fin1>>data1;
            fin1>>data2;
            fin1>>data3;
            fin1>>data4;
            products[i].setProductName(data1);
            products[i].setPrice(data2);
            products[i].setQuantity(data3);
            products[i].setProDesc(data4);    
          
        }


        int op;
        while(1){
            cout<<"Press 1 to Check Your Balance"<<endl;
            cout<<"Press 2 to Show User Details"<<endl;
            cout<<"Press 3 to Place an order"<<endl;
            cout<<"Press 4 to Exit"<<endl;
            cin>>op;
            if(op==1){
                cout<<"Wallet Balance- "<<user[n1].getBalance()<<endl;
            }
            else if(op==2){
                cout<<"Name- "<<user[n1].getUserName()<<" Balance- ";
                cout<<user[n1].getBalance()<<" User Id- ";
                cout<<user[n1].getUserId()<<" Address- ";
                cout<<user[n1].getUserAddress()<<endl;
            }
            else if(op==3){
                cout<<"************ Products List and There Available Quantity ************"<<endl;
                for (int i=0;i<n4;i++){
                    cout<<"Press "<<i<<" to Buy- "<<products[i].getProductName()<<" Price-";
                    cout<<products[i].getProductPrice()<<" Quantity Available-";
                    cout<<products[i].checkQty()<<" About Product-";
                    cout<<products[i].getProductDesc()<<" "<<endl;
                }
                    int op1,op3;
                    cin>>op1;
                    cout<<"How much quantity of this item"<<endl;
                    cin>>op3;
                    Cart cart;
                    if(products[op1].checkQty()>0)
                        {
                            cart.addProduct(products[op1].getProductPrice(),op3);
                            products[op1].updateQty(op3);
                            user[n1].updateBalance(cart.getBill());
                            string tp=products[op1].getProductName()+" "+products[op1].getProductDesc()+" "+to_string(products[op1].getProductPrice())+" "+to_string(op3);
                            cout<<tp<<endl;
                            fout2.open("cart.txt",std::ios_base::app);
                            fout2<<tp<<endl;
                            fout2.close();
                            fout2.open("users.txt");
                            for(int i=0;i<n3;i++){
                                fout2<<user[i].getUserName()<<" ";
                                fout2<<user[i].getBalance()<<" ";
                                fout2<<user[i].getUserId()<<" ";
                                fout2<<user[i].getUserAddress()<<endl;

                            }
                            
                            fout2.close();
                            fout2.open("products.txt");
                            for(int i=0;i<n4;i++){
                                fout2<<products[i].getProductName()<<" ";
                                fout2<<products[i].getProductPrice()<<" ";
                                fout2<<products[i].checkQty()<<" ";
                                fout2<<products[i].getProductDesc()<<" "<<endl;
                            }
                            
                            fout2.close();

                        }
                    else
                        {
                            cout<<"Product out of stock"<<endl;
                        }

                }
            
            else{
                break;
            }

        }
        // for (int i=0;i<n;i++){
        //     cout<<"Press "<<i<<"to buy ";

        // }
        // cout<<"Press -1 To exit ";
        
        if(op==-1){
            cout<<"Thanks For Visiting ROTARI!";
        }
        else{

        }

        fin1.close();

        }
        //outside_login
        else{
            cout<<endl<<"Wrong Password!"<<endl;
        }
        

        

    }


       

 
    
    return 0;
}