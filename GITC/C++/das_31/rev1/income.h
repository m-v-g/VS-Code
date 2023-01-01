#include <iostream>
class Income
{
    public:
        char name;
        double fromStore;
        double fromTender;
        double fromInstalation;
        double fromCashBack;
        double fromService;

        double total;

    
        Income(){}

        Income(Income& other) //konstruktor kopirovaniya
        {
            this->name = other.name;
            this->fromStore = other.fromStore;
            this->fromTender = other.fromTender;
            this->fromInstalation = other.fromInstalation;
            this->fromCashBack = other.fromCashBack;
            this->fromService = other.fromService;
            this->total = other.total;
        }

        Income(char na, double st, double te, double in, double ca, double se)
        {
            name = na;
            fromStore = st;
            fromTender = te;
            fromInstalation = in;
            fromCashBack = ca;
            fromService = se;

            total = st + te + in + ca + se; 
        }

        float compear(const Income temp1,const Income temp2) //TODO hamematelu funkciya
        {
            int na, st, te, in, ca, se, to;

            if(temp1.name > temp2.name) na = 1;
            else if(temp1.name < temp2.name) na = -1;
            else na = 0;

            if(temp1.fromStore > temp2.fromStore) st = 1;
            else if(temp1.fromStore < temp2.fromStore) st = -1;
            else st = 0;

            if(temp1.fromTender > temp2.fromTender) te = 1;
            else if(temp1.fromTender < temp2.fromTender) te = -1;
            else te = 0;

            if(temp1.fromInstalation > temp2.fromInstalation) in = 1;
            else if(temp1.fromInstalation < temp2.fromInstalation) in = -1;
            else in = 0;

            if(temp1.fromCashBack > temp2.fromCashBack) ca = 1;
            else if(temp1.fromCashBack < temp2.fromCashBack) ca = -1;
            else ca = 0;

            if(temp1.fromService > temp2.fromService) se = 1;
            else if(temp1.fromService < temp2.fromService) se = -1;
            else se = 0;

            if(temp1.total > temp2.total) to = 1;
            else if(temp1.total < temp2.total) to = -1;
            else to = 0;

            return (na + st + te + in + ca + se + to) / 7; //! aveli xelaci ban bdi mtacvi
        }

        void print()
        {
            std::cout << "-----------------" << std::endl;
            std::cout << "Name:\t" << name << std::endl;
            std::cout << "From Store:\t" << fromStore << std::endl;
            std::cout << "From Tender:\t" << fromTender << std::endl;
            std::cout << "From Instalation:\t" << fromInstalation << std::endl;
            std::cout << "From Cash Back:\t" << fromCashBack << std::endl;
            std::cout << "From Service:\t" << fromService << std::endl;
            std::cout << "________________" << std::endl;
            std::cout << "AVERAGE:\t" << total << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& tpel, const Income obj)
        {
            std::cout << "==============" << std::endl;
            tpel << "Name:\t" << obj.name << std::endl;
            tpel << "From Store:\t" << obj.fromStore << std::endl;
            tpel << "From Tender:\t" << obj.fromTender << std::endl;
            tpel << "From Instalation:\t" << obj.fromInstalation << std::endl;
            tpel << "From Cash Back:\t" << obj.fromCashBack << std::endl;
            tpel << "From Service:\t" << obj.fromService << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
            tpel << "AVERAGE:\t" << obj.total << std::endl;
            return tpel;
        }

        Income& operator= (const Income other) //operator prisvoivoniya
        {
            this->name = other.name;
            this->fromStore = other.fromStore;
            this->fromTender = other.fromTender;
            this->fromInstalation = other.fromInstalation;
            this->fromCashBack = other.fromCashBack;
            this->fromService = other.fromService;
            this->total = other.total;
            return *this;
        }

        bool operator== (const Income& other) //operator sravneniya
        {
            if(this == &other) return true; //ete hamematum enq 2 nuyn obyektner@
            else if(this->name != other.name) return false;
            else if(this->fromStore != other.fromStore) return false;
            else if(this->fromTender != other.fromTender) return false;
            else if(this->fromInstalation != other.fromInstalation) return false;
            else if(this->fromCashBack != other.fromCashBack) return false;
            else if(this->fromService != other.fromService) return false;
            else if(this->total != other.total) return false;
            return true; //ete sqan ban@ ancel enq uremn havasar en
        }

        bool operator!= (Income& other)
        {
            float cmp = compear(*this, other);
            if(cmp == 0) return false;
            else return true;
        }

        bool operator< (Income& other)
        {
            float cmp = compear(*this, other);
            if(cmp < 0) return true;
            else return false;
        }

        bool operator> (Income& other)
        {
            float cmp = compear(*this, other);
            if(cmp > 0) return true;
            else return false;
        }

        bool operator<= (Income& other)
        {
            float cmp = compear(*this, other);
            if(cmp <= 0) return true;
            else return false;
        }

        bool operator>= (Income& other)
        {
            float cmp = compear(*this, other);
            if(cmp >= 0) return true;
            else return false;
        }

        const Income operator+ (const Income& other)
        {
            Income temp;
            temp.name = this->name + other.name;
            temp.fromStore = this->fromStore + other.fromStore;
            temp.fromTender = this->fromTender + other.fromTender;
            temp.fromInstalation = this->fromInstalation + other.fromInstalation;
            temp.fromCashBack = this->fromCashBack + other.fromCashBack;
            temp.fromService = this->fromService + other.fromService;
            temp.total = this->total + other.total;
            return temp;
        }

        const Income operator- (const Income& other)
        {
            Income temp;
            temp.name = this->name - other.name;
            temp.fromStore = this->fromStore - other.fromStore;
            temp.fromTender = this->fromTender - other.fromTender;
            temp.fromInstalation = this->fromInstalation - other.fromInstalation;
            temp.fromCashBack = this->fromCashBack - other.fromCashBack;
            temp.fromService = this->fromService - other.fromService;
            temp.total = this->total - other.total;
            return temp;
        }

         const Income operator* (const Income& other)
        {
            Income temp;
            temp.name = this->name * other.name;
            temp.fromStore = this->fromStore * other.fromStore;
            temp.fromTender = this->fromTender * other.fromTender;
            temp.fromInstalation = this->fromInstalation * other.fromInstalation;
            temp.fromCashBack = this->fromCashBack * other.fromCashBack;
            temp.fromService = this->fromService * other.fromService;
            temp.total = this->total * other.total;
            return temp;
        }

         const Income operator/ (const Income& other)
        {
            Income temp;
            temp.name = this->name / other.name;
            temp.fromStore = this->fromStore / other.fromStore;
            temp.fromTender = this->fromTender / other.fromTender;
            temp.fromInstalation = this->fromInstalation / other.fromInstalation;
            temp.fromCashBack = this->fromCashBack / other.fromCashBack;
            temp.fromService = this->fromService / other.fromService;
            temp.total = this->total / other.total;
            return temp;
        }

        const Income& operator+= (const Income& other)
        {
            this->name += other.name;
            this->fromStore += other.fromStore;
            this->fromTender += other.fromTender;
            this->fromInstalation += other.fromInstalation;
            this->fromCashBack += other.fromCashBack;
            this->fromService += other.fromService;
            this->total += other.total;
            return *this;
        }

        const Income& operator-= (const Income& other)
        {
            this->name -= other.name;
            this->fromStore -= other.fromStore;
            this->fromTender -= other.fromTender;
            this->fromInstalation -= other.fromInstalation;
            this->fromCashBack -= other.fromCashBack;
            this->fromService -= other.fromService;
            this->total -= other.total;
            return *this;
        }

         const Income& operator*= (const Income& other)
        {
            this->name *= other.name;
            this->fromStore *= other.fromStore;
            this->fromTender *= other.fromTender;
            this->fromInstalation *= other.fromInstalation;
            this->fromCashBack *= other.fromCashBack;
            this->fromService *= other.fromService;
            this->total *= other.total;
            return *this;
        }

         const Income& operator/= (const Income& other)
        {
            this->name /= other.name;
            this->fromStore /= other.fromStore;
            this->fromTender /= other.fromTender;
            this->fromInstalation /= other.fromInstalation;
            this->fromCashBack /= other.fromCashBack;
            this->fromService /= other.fromService;
            this->total /= other.total;
            return *this;
        }

        const Income& operator++ () //prefix increment
        {
            this->name++;
            this->fromStore++;
            this->fromTender++;
            this->fromInstalation++;
            this->fromCashBack++;
            this->fromService++;
            this->total++;
            return *this;
        }

        const Income& operator++ (int tmp) //postfix increment
        {
            Income temp = *this;
            this->name++;
            this->fromStore++;
            this->fromTender++;
            this->fromInstalation++;
            this->fromCashBack++;
            this->fromService++;
            this->total++;
            return temp;
        }

        const Income& operator-- () //prefix decrement
        {
            this->name--;
            this->fromStore--;
            this->fromTender--;
            this->fromInstalation--;
            this->fromCashBack--;
            this->fromService--;
            this->total--;
            return *this;
        }

        const Income& operator-- (int tmp) //postfix decrement
        {
            Income temp = *this;
            this->name--;
            this->fromStore--;
            this->fromTender--;
            this->fromInstalation--;
            this->fromCashBack--;
            this->fromService--;
            this->total--;
            return temp;
        }

        operator bool()
        {
            return this->total;
        }

        operator int()
        {
            return this->total;
        }

        operator float()
        {
            return this->total;
        }

        operator double()
        {
            return this->total;
        }

        operator char()
        {
            return this->name;
        }

        operator std::string()
        {
            return this->name + "\0";
        }

        double& operator[](int index)
        {
            switch (index)
            {
            case 0:
                //return this->name;
                break;

            case 1:
                return this->fromStore;
                break;

            case 2:
                return this->fromTender;
                break;
            
            case 3:
                return this->fromInstalation;
                break;

            case 4:
                return this->fromCashBack;
                break;   

            case 5:
                return this->fromService;
                break; 

            case 6:
                return this->total;
                break;

            default:
                break;
            }
        }
};