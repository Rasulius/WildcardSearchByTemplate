// WildcardFilterSearch.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>

using namespace std;

// � ������ ������ ���������� ������ �� ������ ���������� ������ ������

bool FindText(const string searchText, string searchTemplate){
	const int  height = searchText.size() + 1;
	const int  width = searchTemplate.size() + 1;
	
	// �������� ������
	bool **booleanArray = new bool*[height];
	for (int i = 0; i < height; i++){
		booleanArray[i] = new bool[width];
		for (int j = 0; j < width; j++){
			booleanArray[i][j] = false;
		}
	}
			
	// ������������� ��� ���� � false
	for (unsigned int i = 0; i <= searchText.size(); ++i)
		for (unsigned int j = 0; j <= searchTemplate.size(); ++j)
			booleanArray[i][j] = false;
	
	booleanArray[0][0] = true;

	// ���� �� �������.
	for (unsigned int i = 1; i <= searchText.size(); i++)
		for (unsigned  int j = 1; j <= searchTemplate.size(); j++)
			if (searchText[i - 1] == searchTemplate[j - 1] || searchTemplate[j - 1] == '?')
				booleanArray[i][j] = booleanArray[i - 1][j - 1];
			else if (searchTemplate[j - 1] == '*')
				booleanArray[i][j] = booleanArray[i][j - 1] || booleanArray[i - 1][j];
    // �������� ��������� 
	bool result = booleanArray[searchText.size()][searchTemplate.size()];
	// ������� ������
	for(int i = 0; i < height; i++){
		delete[] booleanArray[i];
	}
	delete[] booleanArray;
	
	return result;
}

void checkFind(bool result){
	if (result)
		cout << "Result: find!!!" << endl;
	else 
		cout << "Result: not find" << endl;
}

void main()
{
	// �������� ������ ������� �� ���� �������� ��������
	checkFind(FindText("Masha i medved", "Ma*"));
	checkFind(FindText("Masha i medved", "?sh?"));	
	checkFind(FindText("samolet", "?am*"));
	cin.get();
}


