FROM n-queens-builder:latest as builder
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN make all

FROM n-queens-base:latest
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/dist/n-queens /usr/src/app
ENTRYPOINT ["./n-queens"]