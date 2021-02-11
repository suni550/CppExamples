

class MutliplicationOperator {
public: 
     MutliplicationOperator();
    ~MutliplicationOperator();

    MutliplicationOperator operator+( const MutliplicationOperator& rhs);

    void setNum1(int);
    void setNum2(int);

    MutliplicationOperator operator*(const MutliplicationOperator& rhs);
    int getResult();

private:
    int m_num1, m_num2,m_mulResult;

};