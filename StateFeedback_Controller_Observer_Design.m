%% Linearization Point
q1 = pi/4;
q2 = pi/4;
g = 9.81;
X0=[q1+.1 q2-.2 0 0];
T=.001;
NewPanto=0;
%% System Parameters
Parameters = [11.8421
0.4216
0.1005
5.6072
1.1523
28.1160
0.0111];
%% Linear System Definition
M = [Parameters(1)+2*Parameters(2)*cos(q2),  Parameters(3)+Parameters(2)*cos(q2);
    Parameters(3)+Parameters(2)*cos(q2),     Parameters(3)];

F = [Parameters(6), 0;
    0, Parameters(7)];

K = [-Parameters(4)*g*sin(q1)-sin(q1+q2)*g*Parameters(5),  -sin(q1+q2)*g*Parameters(5);
    -sin(q1+q2)*g*Parameters(5),                   -sin(q1+q2)*g*Parameters(5)];

A = [zeros(2,2),    eye(2,2);
     -M^-1*K,        -M^-1*F];

B = [zeros(2,2);
    M^-1]*[1;0];

C = [1 0 0 0;
     0 1 0 0];

%% Stability Analysis
EigenValues=eig(A)

%% Controllability and Controller Gain Design
Pc=ctrb(A,B)
rank(Pc)
p=[-15, -14, -11, -12];
K = place(A,B,p)
%% Observability and Estimator Gain Design
Po=obsv(A,C)
rank(Po)
po=[-150, -140, -110, -120];
L = transpose(place(A', C',po))