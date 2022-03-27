#pragma once
#include<iostream>
#include<string>
#include <map>
#include "Direction.hpp"
#include<vector>
using ariel::Direction;
namespace ariel{
class Notebook
{
private:
/**
 * @brief 3 nested maps: The keys in the first map represent the page and the values is a second map.
 * The keys in the second map represent the row and the values is a third map.
 * The keys in the third map represent the column and the value is the char written in that place
 * 
 */
std::map<int,std::map<int , std::map<int,char>>> notebook;
int row_len;
public:
    Notebook(){
        row_len=99;
    }
    ~Notebook(){}
    /**
     * @brief A function that write the text the user want, in the page he wish to write at the row and column he want, in the direction he want.
     * 
     * @param page - The page in the notebook
     * @param row - The row in the page
     * @param col - The column in the page.
     * @param dir - The direction how to write the text
     * @param text - The text the user want to write.
     */
	void write(int page, int row, int col,Direction dir,std::string const &text);
    /**
     * @brief A funtion the return a string of what written in the note book at the page,row,column and the dirction the user wish to read.
     * 
     * @param page - The page in the notebook
     * @param row - The row
     * @param col - The column 
     * @param dir - The direction
     * @param length - The length of how many chars to read.
     * @return std::string - what written.
     */
	std::string read(int page,int row,int col,Direction dir,int length);
    /**
     * @brief Erase the chars at the requested spot from the user.
     * replace the deleted word with ~
     * 
     * @param page page
     * @param row row
     * @param col column
     * @param dir direction to erase
     * @param length how many chars do erase.
     */
    void erase(int page,int row,int col,Direction dir,int length);
    /**
     * @brief shows the notebook's page in a reasonable way. For example:
	    98:  _________
		99:  ___~_____
		100: __a~cd___
		101: ___~_____
		102: _________
     * 
     * @param page - page to show.
     */
    void show(int page);

};

  
}