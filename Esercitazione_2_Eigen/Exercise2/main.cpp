#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


// PaLu solve the linear system Ax=b with the use of the PALU decomposition method
// errRelPaLu the relative error of the numerical solution respect to the analytical solution
VectorXd PaLu(const MatrixXd& A, const VectorXd& b, double& errRelPaLu)
{
    int n = A.rows();
    VectorXd solution = -1*VectorXd::Ones(n);
    VectorXd x = A.fullPivLu().solve(b);
    errRelPaLu = (x - solution).norm()/solution.norm();
    return x;
}
// Qr solve the linear system Ax=b with the use of the QR decomposition method
// errRelQr the relative error of the numerical solution respect to the analytical solution

VectorXd Qr(const MatrixXd& A, const VectorXd& b, double& errRelQr)
{
    int n = A.rows();
    VectorXd solution = -1*VectorXd::Ones(n);

    VectorXd x = A.fullPivHouseholderQr().solve(b);
    errRelQr = (x - solution).norm() / solution.norm();
    return x;
}

int main()
{
    Matrix2d A1;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02,
        8.320502943378437e-01, -9.992887623566787e-01;
    Vector2d b1;
    b1 << 5.169911863249772e-01, 1.672384680188350e-01;
    Matrix2d A2;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01,
        8.320502943378437e-01, -8.324762492991313e-01;
    Vector2d b2;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;
    Matrix2d A3;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01,
        8.320502943378437e-01, -8.320502947645361e-01;
    Vector2d b3;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;




    double errRelPaLu, errRelQr;


    cout << "Soluzione A2x=b2 con il metodo PALU" << endl;
    cout << PaLu(A2, b2, errRelPaLu) << endl;
    cout << "Errore relativo soluzione A2x=b2 con il metodo PALU = " << errRelPaLu << endl;
    cout << "Soluzione A2x=b2 con il metodo QR" << endl;
    cout << Qr(A2, b2, errRelQr) << endl;
    cout << "Errore relativo soluzione A2x=b2 con il metodo QR = " << errRelQr << endl;

    cout << "Soluzione A1x=b1 con il metodo PALU" << endl;
    cout << PaLu(A1, b1, errRelPaLu) << endl;
    cout << "Errore relativo soluzione A1x=b1 con il metodo PALU = " << errRelPaLu << endl;
    cout << "Soluzione A1x=b1 con il metodo QR" << endl;
    cout << Qr(A1, b1, errRelQr) << endl;
    cout << "Errore relativo soluzione A1x=b1 con il metodo QR = " << errRelQr << endl;
    cout << errRelQr << endl;



    cout << "Soluzione A3x=b3 con il metodo PALU" << endl;
    cout << PaLu(A3, b3, errRelPaLu) << endl;
    cout << "Errore relativo soluzione A3x=b3 con il metodo PALU = " << errRelPaLu << endl;
    cout << "Soluzione A3x=b3 con il metodo QR" << endl;
    cout << Qr(A3, b3, errRelQr) << endl;
    cout << "Errore relativo soluzione A3x=b3 con il metodo QR = " << errRelQr << endl;

  return 0;
}


