async function loadStatus() {
    try {
        const response = await fetch('/api/status');
        const data = await response.json();

        updateTemperature(
            'temperature1',
            'temperature1Status',
            data.waterTemperature1
        );

        updateTemperature(
            'temperature2',
            'temperature2Status',
            data.waterTemperature2
        );

        document.getElementById('wifiStatus').textContent =
            data.wifiConnected ? 'WiFi: connected' : 'WiFi: disconnected';

        document.getElementById('uptime').textContent =
            `Uptime: ${data.uptimeSeconds} s`;
    } catch (error) {
        console.error('Failed to load status:', error);
    }
}

function updateTemperature(valueElementId, statusElementId, reading) {
    const valueElement = document.getElementById(valueElementId);
    const statusElement = document.getElementById(statusElementId);

    if (reading.valid) {
        valueElement.textContent = `${reading.valueCelsius.toFixed(1)} °C`;
        statusElement.textContent = 'Sensor OK';
    } else {
        valueElement.textContent = 'ERROR';
        statusElement.textContent = 'Sensor error';
    }
}

loadStatus();
setInterval(loadStatus, 1000);