#ifndef PIDMODEL_HPP
#define PIDMODEL_HPP


class PIDModel{
    public:
        double Kp;
        double Ki;
        double Kd;
        double Tar;
        double PrevErr;
        double Inter;

        PIDModel(double p, double i, double d){
            Kp = p;
            Ki = i;
            Kd = d;
            Tar = 0;
            Inter = 0;
        }

        void Refresh(double p, double i, double d);
        void SetTarget(double Tar);
        double Update(double measure, double dt);
};
#endif