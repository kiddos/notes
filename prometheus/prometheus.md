## pull the images

```sh
docker pull prom/prometheus:v3.8.0
docker pull prom/alertmanager:v0.29.0
docker pull prom/blackbox-exporter:v0.28.0
```

### alertmanager

```yaml
global:
  # The smarthost and SMTP sender used for mail notifications.
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

```


### prometheus.confg

```yaml
global:
  scrape_interval:     60s
  evaluation_interval: 60s

rule_files:
  - "rules.yml"
  # - "first.rules"
  # - "second.rules"

alerting:
  alertmanagers:
  - static_configs:
    - targets:
      - alertmanager:9093

scrape_configs:
  - job_name: prometheus
    static_configs:
      - targets: ['localhost:9090']

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
