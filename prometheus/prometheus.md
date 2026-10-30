## pull the images

versions as of 2026-10-30

```sh
docker pull prom/prometheus:v3.15.1
docker pull prom/alertmanager:v0.34.2
docker pull prom/blackbox-exporter:v0.29.1
docker pull prom/node-exporter:v1.12.1
```

### docker-compose

```yaml
services:
  prometheus:
    image: prom/prometheus:v3.15.1
    command:
      - '--config.file=/etc/prometheus/prometheus.yml'
      - '--storage.tsdb.path=/prometheus'
      - '--web.enable-lifecycle'   # needed for POST /-/reload
    ports:
      - "9090:9090"
    volumes:
      - ./prometheus.yml:/etc/prometheus/prometheus.yml:ro
      - ./rules.yml:/etc/prometheus/rules.yml:ro
      - prom-data:/prometheus
    restart: unless-stopped

  alertmanager:
    image: prom/alertmanager:v0.34.2
    ports:
      - "9093:9093"
    volumes:
      - ./alertmanager.yml:/etc/alertmanager/alertmanager.yml:ro
    restart: unless-stopped

  blackbox-exporter:
    image: prom/blackbox-exporter:v0.29.1
    ports:
      - "9115:9115"
    volumes:
      - ./blackbox.yml:/etc/blackbox_exporter/config.yml:ro
    restart: unless-stopped

  node-exporter:
    image: prom/node-exporter:v1.12.1
    pid: host
    network_mode: host   # or "9100:9100" without host network
    command:
      - '--path.rootfs=/host'
    volumes:
      - /:/host:ro,rslave
    restart: unless-stopped

volumes:
  prom-data:
```

```sh
docker compose up -d
```

### alertmanager

```yaml
global:
  # The smarthost and SMTP sender used for mail notifications.
  # gmail: smtp_auth_password is an app password, not the account password
  smtp_smarthost: 'smtp.gmail.com:587'
  smtp_from: '...@gmail.com'
  smtp_auth_username: '...@gmail.com'
  smtp_auth_password: ''
  smtp_require_tls: true

route:
  receiver: 'gmail-notifications'

receivers:
  - name: 'gmail-notifications'
    email_configs:
    - to: '...@gmail.com'
      from: '...@gmail.com'
```

### blackbox-exporter


```yaml
modules:
  http_2xx:
    prober: http
    timeout: 5s
    http:
      preferred_ip_protocol: "ip4"
      follow_redirects: true
      valid_status_codes: [200, 201, 202, 203, 204, 205, 206, 207, 208, 226]
  tcp_connect:
    prober: tcp
    timeout: 5s
```


### prometheus.yml

```yaml
global:
  scrape_interval:     60s
  evaluation_interval: 60s

rule_files:
  - "rules.yml"   # relative to this file, so /etc/prometheus/rules.yml

alerting:
  alertmanagers:
  - static_configs:
    - targets:
      - alertmanager:9093

scrape_configs:
  - job_name: prometheus
    static_configs:
      - targets: ['localhost:9090']

  - job_name: node
    static_configs:
      - targets: ['localhost:9100']

  - job_name: 'blackbox_RepSpringWeb'
    metrics_path: /probe
    params:
      module: [http_2xx]  # Refers to the module in blackbox.yml
    static_configs:
      - targets:
        - http://localhost:8080/
    relabel_configs:
      - source_labels: [__address__]
        target_label: __param_target
      - source_labels: [__param_target]
        target_label: instance
      - target_label: __address__
        replacement: localhost:9115  # The address of your Blackbox Exporter
```

### rules.yml

```yaml
groups:
  - name: blackbox
    rules:
      - alert: EndpointDown
        expr: probe_success == 0
        for: 2m
        labels:
          severity: critical
        annotations:
          summary: "{{ $labels.instance }} probe failed"

  - name: node
    rules:
      - alert: HostOutOfMemory
        expr: node_memory_MemAvailable_bytes / node_memory_MemTotal_bytes * 100 < 10
        for: 5m
        labels:
          severity: warning
        annotations:
          summary: "low memory on {{ $labels.instance }}"

      - alert: High5xxRate
        expr: sum(rate(promhttp_metric_handler_requests_total{code="500"}[5m])) > 0.1
        for: 5m
        labels:
          severity: warning
        annotations:
          summary: "prometheus is returning 500"
```

### check the config / reload

```sh
# syntax check before starting
docker run --rm -v "$PWD:/cfg" --entrypoint promtool prom/prometheus:v3.15.1 check config /cfg/prometheus.yml
docker run --rm -v "$PWD:/cfg" --entrypoint promtool prom/prometheus:v3.15.1 check rules /cfg/rules.yml
docker run --rm -v "$PWD:/cfg" --entrypoint amtool prom/alertmanager:v0.34.2 check-config /cfg/alertmanager.yml
docker run --rm -v "$PWD:/cfg" --entrypoint blackbox_exporter prom/blackbox-exporter:v0.29.1 \
  --config.file=/cfg/blackbox.yml --config.check

# apply config changes without restarting (needs --web.enable-lifecycle)
curl -X POST http://localhost:9090/-/reload

# targets health
curl -s http://localhost:9090/api/v1/targets | jq -r '.data.activeTargets[] | "\(.labels.job)\t\(.health)"'

# pending / firing alerts
curl -s http://localhost:9093/api/v2/alerts | jq -r '.[] | "\(.labels.alertname)\t\(.status.state)"'
```

UI: prometheus `:9090`（`/targets`、`/rules`、`/alerts`）、alertmanager `:9093`（`/#/alerts`）
