FROM debian:buster

COPY srcs/nginx-conf ./root
COPY srcs/wordpress-5.4.tar.gz ./root
COPY srcs/wp-config.php ./root
COPY srcs/config.inc.php ./root
COPY srcs/start.sh ./root
COPY srcs/autoindex_on.sh ./root
COPY srcs/autoindex_off.sh ./root

# UPDATE

RUN apt-get update

#INSTALL ALL REQUIS

RUN apt-get install -y procps
RUN apt-get install -y wget
RUN apt-get install nano
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server

# START

CMD bash root/start.sh