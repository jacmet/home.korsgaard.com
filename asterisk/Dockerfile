FROM debian:11.8-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      asterisk && \
    apt-get autoremove -y && \
    apt-get autoclean -y && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /var/cache/apt

EXPOSE 5060/udp 5060/tcp

VOLUME /etc/asterisk

CMD ["/usr/sbin/asterisk", "-vvvdddf", "-T", "-W", "-U", "asterisk", "-p"]
