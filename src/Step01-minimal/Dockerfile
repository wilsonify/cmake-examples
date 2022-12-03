FROM step01-minimal-builder:latest as builder
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN make all

FROM step01-minimal-base:latest
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/dist/tutorial /usr/src/app 
ENTRYPOINT ["./tutorial"]