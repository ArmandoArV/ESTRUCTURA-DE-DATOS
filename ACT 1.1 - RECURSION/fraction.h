class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);
        Fraction();
        ~Fraction();
        void getNumerator();
        void getDenominator();
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        void reduce();
};