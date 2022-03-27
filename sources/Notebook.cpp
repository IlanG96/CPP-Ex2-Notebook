#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
constexpr auto DEAFULT_CHAR ='_';
constexpr auto DELETED_CHAR ='~';

void Notebook::write(int page,int row,int col,Direction dir,string const & text){
    if(dir==Direction::Horizontal &&(unsigned long)col+text.length()>Notebook::row_len){
        throw out_of_range("ERR:column number + the text is greater then 100 which is the max row length");
    }
    if(page<0 || row <0 || col<0 ||col>Notebook::row_len){
        throw out_of_range("ERR:The function can accept negetive values or the column number entered is greater then 100");
    }
    int flag=0;
    for (char c: text)
    {
        if(isprint(c)==0||c==DELETED_CHAR){
            throw runtime_error("ERR:One of the characters in the word is not a printable character and you cannot write ~");    
        }
        try{
        if(this->notebook.at(page).at(row).at(col)!= DEAFULT_CHAR)
        {
            flag=1;
        }
        }
        catch(exception &e){
            this->notebook[page][row][col]=DEAFULT_CHAR;
        }
        if (flag==1)
        {
            throw runtime_error("ERR:Something written already at that slot");
        }
        
        this->notebook[page][row][col]=c;
        if (dir==Direction::Horizontal)
        {
            if(col==this->row_len){
                row++;
                col=0;
            }
            col++;
        }
        else{
            row++;
        }
    
    }


}

string Notebook::read(int page,int row,int col,Direction dir,int length){
    string ans;
    if(page<0 || row <0 || col<0||length<0||col>Notebook::row_len){
        throw out_of_range("ERR:The function can accept negetive values or the column number entered is grater then 100");
    }
    
    if(dir==Direction::Horizontal &&col+length>Notebook::row_len+1){
        throw out_of_range("ERR:column number + the text is greater then 100 which is the max row length");
    }
    if (dir==Direction::Horizontal)
    {
        for (int i = col; i < col+length; i++)
        {
            try{
                ans+=this->notebook[page][row].at(i);
            }
            catch(exception &e){
                this->notebook[page][row][i]=DEAFULT_CHAR;
                ans+=DEAFULT_CHAR;
            }       
        }
    }
    else{
       for (int i = row; i < row+length; i++)
        {
            try{    
                ans+=this->notebook[page][i].at(col);
            }
            catch(exception &e){
                this->notebook[page][i][col]=DEAFULT_CHAR;
                ans+=DEAFULT_CHAR;
            }
        } 
}




return ans;

}
void Notebook::erase(int page,int row,int col,Direction dir,int length){
    if(page<0 || row <0 || col<0||length<=0||col>Notebook::row_len){
        throw out_of_range("ERR:The function can accept negetive values or the column number entered is grater then 100");
    }
    if(dir==Direction::Horizontal &&col+length>Notebook::row_len+1){
        throw out_of_range("ERR:column number + the text is greater then 100 which is the max row length");
    }
    if (dir==Direction::Horizontal){
        for (int i = col; i < col+length; i++){
            try{
                this->notebook.at(page).at(row).at(i)=DELETED_CHAR;
            }
            catch(exception &e){
                this->notebook[page][row][i]=DELETED_CHAR;
            }       
        }
    }
    if(dir==Direction::Vertical){
       for (int i = row; i < row+length; i++){
            try{    
                this->notebook.at(page).at(i).at(col)=DELETED_CHAR;
            }
            catch(exception &e){
                this->notebook[page][i][col]=DELETED_CHAR;
            }
        } 
    }
        


}
void Notebook::show(int page){
    int last_row=0;
     int row=0;
    if(page<0){
        throw out_of_range("ERR:The Page can be a negetive value");
    }
    try{
        std::map<int , std::map<int,char>>::iterator it = this->notebook.at(page).begin();
        while (it!=this->notebook.at(page).end()){
            row=it->first;
            if (row>last_row){
                last_row=row;
            }  
            it++;
        }
    }
    catch(exception &e){}
    row=0;
    cout << "Page: "<<page << endl;
    while (row<last_row+3)
    {
        cout <<read(page,row,0,Direction::Horizontal,Notebook::row_len) <<"  :"<< row<< endl;
        row++;
    }
}

/**
 * @brief Main Function for testing.
 * 
 * @return int 
 */
// int main()
// {
//     Notebook test;
//     //cout << test.read(2,3,4,Direction::Horizontal,5) << endl;
//     test.write(2,3,4,Direction::Horizontal,"HAIM");
//     test.write(2,3,9,Direction::Horizontal,"HOMO");
//     //cout << test.read(2,3,4,Direction::Horizontal,5) << endl;
//     //test.erase(2,3,4,Direction::Horizontal,5);
//     //cout << test.read(2,3,4,Direction::Horizontal,5) << endl;
//     //test.write(2,4,5,Direction::Horizontal,"Testt");
//     //cout << test.read(2,3,4,Direction::Horizontal,10) << endl;
//     test.write(2,4,4,Direction::Vertical,"AIM");
//     test.write(2,8,4,Direction::Vertical,"HOMO");
//     //cout << test.read(2,4,5,Direction::Horizontal,5) << endl;
//     //printf("---------------------------------------------\n");
//     test.write(2,1,0,Direction::Horizontal, "GFDGDFGJDFGJKFDHGFDUGFDJKGFDLGJFDAAIGLHFDAGUJADFJSDABFDSFOSDJGUJFDHGFDGJFSD;LAGISFDOGFDIGHFDGJDFGFDA");
//     test.show(2);
//     return 0;
// }