# Deployemnt
---

## Prerequisites

Jenkins is an automated build system available for several platforms including linux, however the included build scripts are intended for Windows. The choice was motivated by the available developlemt hardware and the planned integrations.

## Azure Cloud

See the [AzureBuildTemplate folder](/AzureBuildTemplate) for a configuration template containing all the needed resources.

## Jekins

The unreal project can be build tbrough the commandline interface using the provided [batch file](CLI_Build_Script.bat).

### Notifications

Jenkins has many notifcation methods. We use the webhooks to push to our Discord server.