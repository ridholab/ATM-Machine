#include <iostream>
using namespace std;

int transaksi_baru;
float jumlah_saldo = 0.0;

void atm_machine_transaction(){

    cout << "Menu yang Tersedia pada Mesin ATM" << endl;

    cout << "1. Setor Tunai" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Cek Saldo" << endl;
    cout << "\n";

    int option;

    cout << "Your option: ";
    cin >> option;

    float jumlah_penarikan;
    float jumlah_setoran;

    switch(option)

    {
        // Case Untuk Setoran Tunai
        case 1:
            cout << "\nMasukkan Jumlah Setoran Tunai: ";
            cin >> jumlah_setoran;
            jumlah_saldo += jumlah_setoran;
            
            cout << "Saldo Akhir Anda Rp. " << jumlah_saldo << ". Thanks for depositing!" << endl;
            cout << "Apakah Anda Ingin Melakukan Transaksi yang Lain?\nTekan 1 untuk 'Memproses' dan 2 untuk 'Keluar'\n" << endl;
              
            cout << "Your option: ";
            cin >> transaksi_baru;

            if (transaksi_baru == 1){
                atm_machine_transaction();
            }
        break;

        // Case untuk Tarik Tunai
        case 2:
            
            cout << "\nMasukkan Jumlah Penarikan Tunai: ";
            cin >> jumlah_penarikan;

            if (jumlah_penarikan > jumlah_saldo)
            {
                cout << "Saldo Tidak Mencukupi! Silahkan Melakukan Proses Setor Tunai Terlebih Dahulu." << endl;
                cout << "Apakah Anda Ingin Melakukan Transaksi yang Lain?\nTekan 1 untuk 'Memproses' dan 2 untuk 'Keluar'\n"<< endl;

                cout << "Your option: ";
                cin >> transaksi_baru;

                if (transaksi_baru == 1){
                    atm_machine_transaction();
                }

            }
            else
            {
                jumlah_saldo -= jumlah_penarikan;

                cout << "Anda Telah Melakukan Penarikan Tunai Rp. " << jumlah_penarikan << " dan Sisa Saldo Anda Rp. " << jumlah_saldo << endl;
                cout << "Apakah Anda Ingin Melakukan Transaksi yang Lain?\nTekan 1 untuk 'Memproses' dan 2 untuk 'Keluar'\n" << endl;

                cout << "Your option: ";
                cin >> transaksi_baru;

                if (transaksi_baru == 1){
                    atm_machine_transaction();
                }
            }
        break;

        // Case untuk Cek Saldo
        case 3:
            cout << "Sisa Saldo Anda Rp. " << jumlah_saldo << endl;
            cout << "Apakah Anda Ingin Melakukan Transaksi yang Lain?\nTekan 1 untuk 'Memproses' dan 2 untuk 'Keluar'\n" << endl;

            cout << "Your option: ";
            cin >> transaksi_baru;

            if (transaksi_baru == 1){
                atm_machine_transaction();
            }
        break;
    }
}

int main()
{
    atm_machine_transaction();
    cout << "Terima Kasih Telah Melakukan Transaksi!";
    return 0;
}
