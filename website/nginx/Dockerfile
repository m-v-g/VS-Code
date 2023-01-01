FROM nginx:latest

RUN apt-get update && \
    apt-get install zip -y

RUN rm /etc/nginx/conf.d/*
COPY ./website.conf /etc/nginx/conf.d/website.conf

COPY ./lib_letsencrypt.zip ./etc_letsencrypt.zip /tmp/
RUN unzip /tmp/etc_letsencrypt.zip -d /tmp/
RUN unzip /tmp/lib_letsencrypt.zip -d /tmp/
RUN cp /tmp/etc/letsencrypt /etc/ -r
RUN cp /tmp/var/lib/letsencrypt /var/lib/ -r