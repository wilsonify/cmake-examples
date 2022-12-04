FROM step04-testable-builder:latest as builder
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN make all

FROM step04-testable-base:latest
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/dist/tutorial /usr/src/app 
ENTRYPOINT ["./tutorial"]