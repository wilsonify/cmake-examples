FROM weather-statistics-builder:latest as builder
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN make all

FROM weather-statistics-base:latest
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/dist/weather-statistics /usr/src/app
ENTRYPOINT ["./weather-statistics"]