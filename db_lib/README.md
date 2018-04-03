1. mysql.h的安装编译方案
`sudo yum install mysql-devel -y    //RHEL,Centos,Fedora`
`sudo apt-get install libmysqlclient-dev -y  //Ubuntu`
`sudo  find /usr/ -name 'mysql.h'`
`gcc -I/usr/include/mysql ...`