#include "franka_inria_inverse_dynamics_solver/get_FrictionTorque.h"

Eigen::VectorXd get_friction(Eigen::VectorXd dq)
{
    int NUMBER_OF_JOINTS = 7;

    /* SIGMOIDAL FUNCTION */
    double* A = new double[NUMBER_OF_JOINTS];
    double* qdotsign = new double[NUMBER_OF_JOINTS];
    double* alpha = new double[NUMBER_OF_JOINTS];

    Eigen::VectorXd tau_f(NUMBER_OF_JOINTS);

    // 24 Feb 2019
    A[0] = 0.54615;
    A[1] = 0.87224;
    A[2] = 0.64068;
    A[3] = 1.2794;
    A[4] = 0.83904;
    A[5] = 0.30301;
    A[6] = 0.56489;

    qdotsign[0] = 0.039533;
    qdotsign[1] = 0.025882;
    qdotsign[2] = -0.04607;
    qdotsign[3] = 0.036194;
    qdotsign[4] = 0.026226;
    qdotsign[5] = -0.021047;
    qdotsign[6] = 0.0035526;

    alpha[0] = 5.1181;
    alpha[1] = 9.0657;
    alpha[2] = 10.136;
    alpha[3] = 5.5903;
    alpha[4] = 8.3469;
    alpha[5] = 17.133;
    alpha[6] = 10.336;

    for(int i=0; i<7; i++)
    {
        tau_f(i) = -A[i]/(1+exp(-alpha[i]*qdotsign[i])) + A[i]/(1+exp(-alpha[i]*(dq(i)+qdotsign[i])));
    }

    delete[] A;
    delete[] qdotsign;
    delete[] alpha;    

    return tau_f;
}
