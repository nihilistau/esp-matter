// Copyright 2023 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <credentials/DeviceAttestationCredsProvider.h>
#include <sdkconfig.h>

#if CONFIG_SEC_CERT_DAC_PROVIDER
namespace chip {
namespace DeviceLayer {

class SecureCertDACProvider : public Credentials::DeviceAttestationCredentialsProvider
{
public:
    SecureCertDACProvider() : Credentials::DeviceAttestationCredentialsProvider() {}

    CHIP_ERROR GetCertificationDeclaration(MutableByteSpan & outBuffer) override;

    CHIP_ERROR GetFirmwareInformation(MutableByteSpan & out_firmware_info_buffer) override;

    CHIP_ERROR GetDeviceAttestationCert(MutableByteSpan & outBuffer) override;

    CHIP_ERROR GetProductAttestationIntermediateCert(MutableByteSpan & outBuffer) override;

    CHIP_ERROR SignWithDeviceAttestationKey(const ByteSpan & messageToSign, MutableByteSpan & outSignBuffer) override;
};

} // namespace DeviceLayer
} // namespace chip
#endif // CONFIG_SEC_CERT_DAC_PROVIDER
