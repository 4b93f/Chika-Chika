FROM debian:buster

COPY srcs/nginx.conf ./root/
COPY srcs/wordpress-5.4.tar.gz ./root/
COPY srcs/wp-config.php ./root/
COPY srcs/config.inc.php ./root/
COPY srcs/wordpress.sql ./root/
COPY srcs/mysql.sh ./root/
COPY srcs/start.sh ./root/

# UPDATE
RUN apt-get update
RUN apt-get upgrade -y

# INSTALL NGINX
RUN apt-get -y install nginx

# INSTALL MYSQL
RUN apt-get -y install mariadb-server

# INSTALL PHP
RUN apt-get -y install php7.3 php-mysql php-fpm php-cli php-mbstring php-json

# INSTALL TOOLS
RUN apt-get -y install wget

# INSTALL VIM
RUN apt-get install vim

# INSTALL PHPMYADMIN
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar xf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages.tar.gz usr/share/phpMyAdmin

# CONFIG PHPMYADMIN

RUN sudo -cp pr /usr/share/phpMyAdmin/config.sample.inc.php /usr/share/phpMyAdmin/config.inc.php
RUN mkdir -p /usr/shar/phpMyAdmin/tmp && chmod 777 /usr/share/phpMyAdmin/tmp
RUN chown -R www-data:www-data /var/lib/phpmyadmin

# CONFIG MYSQL

RUN bash root/mysql.sh

# INSTALL WORDPRESS

RUN tar xf /root/wordpress-5.4.tar.gz
RUN chown -R www-data:www-data /usr/share/phpMyAdmin





# START

CMD bash root/start.sh