

class AdditionOperator {
public: 
     AdditionOperator();
    ~AdditionOperator();

    void setLength(int length);
    void setWidth(int width);

    int getLength();
    int getWidth();
    int calcPerimeter();

    AdditionOperator operator+( const AdditionOperator& rhs);

    void setNum1(int);
    void setNum2(int);

    AdditionOperator operator*(const AdditionOperator& rhs);
    int getResult();

private:
    int m_length, m_width;
    int m_num1, m_num2,m_mulResult;

};