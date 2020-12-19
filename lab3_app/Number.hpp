#ifndef header_hpp
#define header_hpp
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

namespace Lab3 {
	class Number {
	private:
		static const int SZ = 31;	// ������������ ������ �������
		int len;	// ����� ���� � �����
		char a[SZ + 2];	// ������ ������� 31 ������ � + ����
	public:
		// ������������
		Number();	// �������������� ����� �����	(����� 1)
		Number(long long int k);	// �������������� ����� ���������� (������ ������������� �����)	(����� 2) 
		Number(const char* c);	// �������������� ����� �������� �������� char	(����� 3)

		// �������
		char getFullArray() const { return *a; }	// ���������� ��������� �� ������ ���������
		int getLength() const { return len; }
		char* getArray() const;

		// �������
		Number& setArray(char* a0) { strcpy_s(a, a0); return *this; }
		Number& setLength(int l) { len = l; return *this; }
		Number& setSign() { a[0] = (a[0] == '1') ? '0' : '1'; return *this; }	// �������� ���� � ����� �� ��������������� 

		Number sum(const Number& r) const; 		// �������� ���� ����� (����� 5)
		Number sub(const Number& r) const;	// �������� ���� ����� (����� 5)

		// ������������� ���������
		friend std::istream& operator >>(std::istream&, Number& r);	// ���� ����������� ������ �� �������� ������ (����� 4)
		friend std::ostream& operator <<(std::ostream&, const Number& r);	// ����� ����������� ������ �� ������� ������ (����� 4)
		friend Number operator +(const Number& c, const Number& r);
		friend Number operator -(const Number& c, const Number& r);

		// Number operator +(const Number &r) const;	// ������������� �������� �������� �����
		// Number operator -(const Number &r) const;	// ������������� �������� �������� �����

		Number& operator <<=(int n);	// ����� ����� �� n ���� ����� (583->58300 ��� n = 2) (����� 6)
		Number& operator >>=(int n);	// ����� ����� �� n ���� ������ (583->5 ��� n = 2) (����� 7)

		int isAbsMore(const Number& r) const;	// ��������� ���� ����� �� ������ (����� ��� ��������)
		bool isMore(const Number& r) const;		// ��������� ���� ����� (����� 8)
		bool isEqual(const Number& r) const;	// ��������� ���� ����� (����� 8)
		bool isEven() const;	// �������� �������� (true ���� �����)	(����� 9)

		friend bool operator >(const Number& first, const Number& second); // ������������� �������� ���������
		friend bool operator <(const Number& first, const Number& second);
		friend bool operator <=(const Number& first, const Number& second);
		friend bool operator >=(const Number& first, const Number& second);
		friend bool operator ==(const Number& first, const Number& second);

		void reduction();	// ��������� ����� �� ���� 10000053 � 153 � ��
	};
}

#endif
